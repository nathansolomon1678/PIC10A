#include "HomeworkList.h"

#include<vector>
#include<algorithm>
#include<numeric>
#include<stdexcept>
#include<cmath>

HomeworkList::HomeworkList() {} // the default constructor will create an empty collection of homeworks

void HomeworkList::addScore(int score, int maxPossible){
	
	// insert the score and max
	homeworkScores.push_back({ score, maxPossible });
}

double HomeworkList::percentageFromBest(size_t topNumber) const{
	if (topNumber > homeworkScores.size()){ // if number to average exceeds number of scores in collection
		throw std::logic_error("Too few elements to obtain average of requested number of scores");
	}

	// if here, then the averaging can be done

	auto copy{ homeworkScores }; // make a copy to sort

	// will be in ascending order by percent
	std::sort(std::begin(copy), std::end(copy), 
		/* compares two HWs by percent */
		[](const score_max& x, const score_max& y)
		->bool {
			// as decimal divide score by max and compare
			return static_cast<double>(x.score) / x.max < static_cast<double>(y.score) / y.max;
		});

	// biggest values at the end
	// sum the topNumber of HWs with accumulate: the range does not include last element hence to get top N
	// go from crbegin to crbegin+N 
	double total = std::accumulate(std::crbegin(copy),
		std::crbegin(copy) + topNumber, 0., 
			/* add double and HW score by adding percentages */
			[](double x, const score_max& y)->
				double {
					return x += static_cast<double>(y.score) / y.max;
			}
	);

	const double fraction_to_percent = 100;

	// average them and convert to a percent
	double average = fraction_to_percent * total / topNumber;

	/* now round it so that values like 50.99999999999 
	become 60.0000, etc. - helps with roundoff error in
	some calculations */
	const double level = 100000; // how precise to round
	average = std::round(level*average) / level;

	return average; // and return the value
}	

size_t HomeworkList::numberOfHWs() const{
	return homeworkScores.size(); // the size of the vector is the number of HWs it stores
}