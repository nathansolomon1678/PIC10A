#ifndef _WORD_RUN_H_
#define _WORD_RUN_H_

#include <ctime>
#include <fstream>
#include <iostream>
#include <set>
#include <string>

/**
 * @class WordRun Encapsulates a game of Wordle
 */
class WordRun {
public:
    /**
     * Class constructor (no parameters)
     */
    WordRun();

    /**
     * Compares the guessed to the chosen word,
     * and prints hints on which letters are in the word and
     * which letters are in the right place
     * @param guessed_word the word the user has guessed
     */
    void guess(const std::string& guessed_word);

    /**
     * Getter for `won`
     * @returns whether the game has been won yet
     */
    bool hasWon() const;

    /**
     * Getter for `score`
     * @returns -1 if the game is still going, otherwise returns the score
     */
    int getScore() const;

    /**
     * Getter for `duration`
     * @returns the time taken to win, or -1 if the game is still going
     */
    time_t getTime() const;

    /**
     * Getter for `guesses`
     * @returns the number of guesses if the game has been won, otherwise -1
     */
    int getGuesses() const;
private:
    // Using an std::set makes lookups take O(log n) time (since it implements
    // a binary search tree), but choosing a random element of words will
    // take O(n) time (which is fine since we only do it once)
    std::set<std::string> words;
    // `words` and `chosen` don't change after the constructor runs, but since
    // they're set in the constructor body instead of the initializer list,
    // they have to be mutable anyway
    std::string chosen;

    // Miscellaneous member variables to keep track of the status of the game:
    int guesses;
    const time_t start;
    time_t duration;
    bool won;
    int score;

    /**
     * Reads the list of words from `words4.txt` and stores them in `words`
     */
    void setWords();

    /**
     * Chooses a random element of `words` and saves it in `chosen`
     */
    void chooseWord();

    /**
     * Uses the number of guesses and game duration to calculate the score
     */
    void setScore();
};

#endif  // _WORD_RUN_H_
