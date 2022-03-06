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
