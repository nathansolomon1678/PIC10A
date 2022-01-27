#include "HomeworkList.h"

#include <iomanip>
#include <iostream>
#include <string>

int main() {
    std::cout << "Enter student's name: ";
    std::string name = "";
    std::getline(std::cin, name);

    // This HomeworkList object keeps track of all the scores and has member funcs
    // to return the number of assignments and the overall percentage
    HomeworkList list_of_scores;

    bool entering_more_scores = true;
    while (entering_more_scores) {
        // repeat until the user enters 'n', indicating they have no more scores to enter
        int score, max;
        std::cout << "Enter score and max as two values: ";
        std::cin >> score >> max;
        list_of_scores.addScore(score, max);

        std::cout << "More scores? y/n: ";
        char yes_or_no = ' ';
        std::cin >> yes_or_no;
        // Assume user will always enter either 'y' or 'n', so this is valid:
        entering_more_scores = (yes_or_no == 'y');
    }

    // total_number_of_scores and grade can be const since they don't come from user input
    const int total_number_of_scores = list_of_scores.numberOfHWs();
    int num_scores_affecting_grade = 0;
    std::cout << "How many scores should be used in computing the HW grade? ";
    std::cin >> num_scores_affecting_grade;
    const double grade = list_of_scores.percentageFromBest(num_scores_affecting_grade);

    std::cout << "The homework grade for "
              << name
              << " based on the best "
              << num_scores_affecting_grade
              << " homework scores out of "
              << total_number_of_scores
              << " is "
              << std::fixed
              << std::setprecision(2)  // print two digits after decimal
              << grade
              << "%.\n";

    if (grade >= 95.) {
        // If grade is in [95, 100], that's exellent
        std::cout << "This is excellent.\n";
    } else if (grade >= 80.) {
        // If grade is in [80, 95), that's good
        std::cout << "This is good.\n";
    } else if (grade >= 70.) {
        // If grade is in [70, 80), that's decent
        std::cout << "This is decent.\n";
    } else {
        // If grade is in below 70, that's poor
        std::cout << "This is poor.\n";
    }

    return 0;
}
