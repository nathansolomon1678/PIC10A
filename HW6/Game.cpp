#include "Range.h"
#include <ctime>

int main() {
    // Seed the RNG exactly once, before ever using it
    std::srand(std::time(nullptr));
    
    std::cout << "Cards 2-10 are worth their numeric value.\n"
              << "J, Q, K have a value of 11.\n"
              << "An A has a value of 12 as a spade and 1 for other suits.\n"
              << "Over 3 rounds, you will try to reach or exceed a target value, without going over 22!\n"
              << "If you go over, you get -1 points; if you are within range, you get +1 points; otherwise you get 0 points.\n";
    
    int total_score = 0;
    int upper_bound = 22;  // this is a given

    for (int round_num = 1; round_num <= 3; ++round_num) {
        // Repeat the game for 3 rounds

        std::cout << '\n';

        // lower_bound should be a random integer between 17 and 22 (inclusive)
        // That range has 6 possible values, so use mod 6 for the RNG
        // Note that std::rand()%6 must be an integer between 0 and 5 (inclusive)
        int lower_bound = std::rand() % 6 + 17;

        // Keep track of the entire deck to avoid dealing the same card twice
        std::vector<Card> undealt_cards = new_deck();
        std::vector<Card> current_hand = {};

        bool requesting_more_cards = true;
        while (requesting_more_cards) {
            // Deal a card:
            current_hand.push_back(dealCard(undealt_cards));
            int value_of_hand = hand_value(current_hand);

            std::cout << "Target lower bound: " << lower_bound << '\n'
                      << "Hand value is: " << value_of_hand << '\n';
            showHand(current_hand);

            if (inRange(lower_bound, upper_bound, value_of_hand)) {
                // User won this round
                ++total_score;
                std::cout << "You got 1 point.\n";
                break;
            } else if (exceeds(upper_bound, value_of_hand)) {
                // User lost this round
                --total_score;
                std::cout << "You got -1 points.\n";
                break;
            } else {
                // Game isn't automatically over; ask user whether they want to continue
                std::cout << "Deal more? y/n: ";
                char input = ' ';
                std::cin >> input;
                // Assume user enter 'y' or 'n'
                requesting_more_cards = (input == 'y');
            }

            if (!requesting_more_cards) {
                std::cout << "You got 0 points.\n";
            }
        }
    }

    std::cout << "\nYour total score is " << total_score << " point";
    if (total_score == 1) {
        // print "point" (singular)
        std::cout << ".\n";
    } else {
        // print "points" (plural)
        std::cout << "s.\n";
    }
    
    return 0;
}
