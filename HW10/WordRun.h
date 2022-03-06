#ifndef _WORD_RUN_H_
#define _WORD_RUN_H_

#include <ctime>
#include <fstream>
#include <iostream>
#include <set>
#include <string>

class WordRun {
public:
    WordRun();
    void guess(std::string guessed_word);
    bool hasWon() const;
    int getScore() const;
    time_t getTime() const;
    int getGuesses() const;
private:
    // Using an std::set makes lookups take O(log n) time (since it implements
    // a binary search tree), but choosing a random element of words will
    // take O(n) time (which is fine since we only do it once)
    std::set<std::string> words;
    std::string chosen;
    int guesses;
    const time_t start;
    time_t duration;
    bool won;
    int score;
    void setWords();
    void chooseWord();
    void setScore();
};

#endif  // _WORD_RUN_H_
