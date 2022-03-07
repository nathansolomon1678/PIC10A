#include "WordRun.h"

#include <fstream>
#include <iostream>

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
        // If they've played before, there will be a file with their name
        // that has saved their past scores, which we then read through
        int highest_score = 0;
        std::string score = "";
        while (std::getline(previous_scores, score)) {
            // Each line of the file represents the score from one past game
            highest_score = std::max(highest_score, std::stoi(score));
        }
        std::cout << "Your best score is " << highest_score << ".\n";
    } else {
        // If the opening a file immediately puts the stream in a failed
        // state, that indicates that the file doesn't exist
        std::cout << "You have not played before.\n";
    }
    previous_scores.close();

    std::cout << "Would you like to play? y/n:";
    char wants_to_play = ' ';
    std::cin >> wants_to_play;
    if (wants_to_play == 'n') {
        // If they say no, then this breaks out of the `int main()` function,
        // so the game automatically ends
        std::cout << "goodbye\n";
        return 0;
    }
    
    // The rest of the `int main()` function only runs if they did not enter
    // 'n' in response to that last question
    std::cout << "Try to guess a 4-letter word. "
                 "Letters in their rightful place get a '*'. "
                 "Letters of the word not in their place get a '~'. "
                 "Otherwise, a '-' is displayed.\n";

    WordRun Game;

    while (!Game.hasWon()) {
        // As long as they have not yet guessed the word,
        // keep prompting the player to input more guesses
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

    // `scores` is the same as previous_scores except that it's an ofstream
    // instead of an ifstream, so it's writable (or in this case, appendable)
    // This stores their score to a file, so it's saved or the next time
    // they play
    std::ofstream scores(name + ".txt", std::ios_base::app);
    scores << Game.getScore() << '\n';
    scores.close();

    return 0;
}
