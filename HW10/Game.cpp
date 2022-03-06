#include "WordRun.h"
#include <iostream>
#include <fstream>

int main() {
    std::srand(std::time(nullptr));

    std::cout << "Enter your name: ";
    std::string name("");
    std::getline(std::cin, name);
    if (name == "Honesty" || name == "word4") {
        // This would cause a mess, since it would interfere
        // with existing .txt files
        std::cout << "Your name is not \"" << name << "\", you liar.\n";
        return 0;
    }

    std::ifstream previous_scores(name + ".txt");
    if (previous_scores) {
        int max_score = 0;
        std::string score = "";
        while (std::getline(previous_scores, score)) {
            max_score = std::max(max_score, std::stoi(score));
        }
        std::cout << "Your best score is " << max_score << ".\n";
    } else {
        std::cout << "You have not played before.\n";
    }

    std::cout << "Would you like to play? y/n:";
    char wants_to_play = ' ';
    std::cin >> wants_to_play;
    if (wants_to_play == 'n') {
        std::cout << "goodbye\n";
        return 0;
    }

    std::cout << "Try to guess a 4-letter word. "
                 "Letters in their rightful place get a '*'. "
                 "Letters of the word not in their place get a '~'. "
                 "Otherwise, a '-' is displayed.\n";

    WordRun Game;

    while (!Game.hasWon()) {
        std::string guessed_word = "";
        std::cin >> guessed_word;
        Game.guess(guessed_word);
    }

    std::cout << "You won and responded in "
              << Game.getGuesses()
              << " guesses, with a time of "
              << Game.getTime()
              << "s, earning a score of "
              << Game.getScore()
              << ".\n";

    // scores is the same as previous_scores except that it's an ofstream
    // instead of an ifstream
    std::ofstream scores(name + ".txt", std::ios_base::app);
    scores << Game.getScore() << '\n';

    return 0;
}
