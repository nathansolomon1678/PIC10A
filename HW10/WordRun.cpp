#include "WordRun.h"

WordRun::WordRun() :
    words({}),
    chosen(""),
    guesses(0),
    start(std::time(nullptr)),
    duration(0),
    won(false),
    score(0)
{
    setWords();
    chooseWord();
}

void WordRun::setWords() {
    std::ifstream stream("word4.txt");
    std::string new_word = "";
    while (std::getline(stream, new_word)) {
        words.insert(new_word);
    }
}

void WordRun::chooseWord() {
    std::set<std::string>::iterator iter = words.begin();
    size_t index = std::rand() % words.size();
    // Sadly this works in O(n) time, because sets are not actually indexed
    advance(iter, index);
    chosen = *iter;
}

bool WordRun::hasWon() const { return won; }

int WordRun::getScore() const {
    return won ? score : -1; }

time_t WordRun::getTime() const {
    return won ? duration : -1;
}

int WordRun::getGuesses() const {
    return won ? guesses : -1;
}

void WordRun::guess(std::string guessed_word) {
    ++guesses;
    duration = std::time(nullptr) - start;

    if (guessed_word.size() != 4) {
        std::cout << "“wrong size\n";
        return;
    }
    if (words.find(guessed_word) == words.end()) {
        std::cout << "word not among possible words\n";
        return;
    }
    
    std::string display("----\n");
    const int word_length = 4;
    for (int i = 0; i < word_length; ++i) {
        if (guessed_word[i] == chosen[i]) {
            display[i] = '*';
        } else if (chosen.find(guessed_word[i]) != std::string::npos) {
            display[i] = '~';
        }
    }
    std::cout << display;

    won = guessed_word == chosen;
    setScore();
}

void WordRun::setScore() {
    score = std::max(0, 150 - static_cast<int>(duration))
          + std::max(0, 150 - guesses);
}
