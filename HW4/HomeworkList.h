#ifndef __HOMEWORK_LIST__
#define __HOMEWORK_LIST__

#include<vector>
#include<cstddef>

/**
@class HomeworkList can store a bunch of
HW grades with the score earned and the maximum points
available and can compute the average using only the top
scores
*/
class HomeworkList{
public:

	/**
	Constructor: creates a HomeworkAverage class storing no data
	*/
	HomeworkList();

	/**
	This function adds a homework score to the collection of homework grades. The homework grades are all stored
	as percentages out of 100.

	@param score the score on a given homework
	@param maxPossible the maximum possible score for a given homework
	*/
	void addScore(int score, int maxPossible);

	/**
	This function will compute the overall homework percentage by averaging only the top number of scores specified.

	@param topNumber the number of scores to include in the calculated average, for example if topNumber is 3, then the top 3 homework scores
	are used to compute the overall homework average

	@return the homework average: the best topNumber of scores among all scores present
	*/
	double percentageFromBest(size_t topNumber) const;

	/**
	This function returns the number of homework scores stored in the object.

	@return the number of homework scores stored
	*/
	size_t numberOfHWs() const;

private:

	/**
	@struct score_max stores a score and a max value
	*/
	struct score_max {
		int score;
		int max;		
	};	

	// to store the collection of homework scores	
	std::vector< score_max > homeworkScores; 

};


#endif