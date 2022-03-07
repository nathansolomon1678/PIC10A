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
        // Each line will have one word, which we add to the set of words
        words.insert(new_word);
    }
    stream.close();
}

void WordRun::chooseWord() {
    std::set<std::string>::iterator iter = words.begin();
    const size_t index = std::rand() % words.size();
    // Sadly this works in O(n) time, because sets are not actually indexed,
    // but it is possible to use an iterator to traverse the binary search tree
    advance(iter, index);
    chosen = *iter;
}

bool WordRun::hasWon() const { return won; }

int WordRun::getScore() const {
    // Ternary operator!  :)
    return won ? score : -1;
}

time_t WordRun::getTime() const {
    // Ternary operator!  :)
    return won ? duration : -1;
}

int WordRun::getGuesses() const {
    // Ternary operator!  :)
    return won ? guesses : -1;
}

void WordRun::guess(const std::string& guessed_word) {
    ++guesses;
    duration = std::time(nullptr) - start;

    const size_t word_length = 4;
    if (guessed_word.size() != word_length) {
        // This means that they guessed a word with more or less than 4 letters
        std::cout << "wrong size\n";
        return;
    }
    if (words.find(guessed_word) == words.end()) {
        // Checks whether the guess is in our list of 500 valid 4-letter words
        std::cout << "word not among possible words\n";
        return;
    }

    // This function matches the assignment spec, but doesn't match
    // how Wordle actually works. For example, if the chosen word is "into"
    // and the user guesses "book", this function would print "-~~-", but
    // and actual game of Wordle would mark only the first 'o' as being in
    // the chosen word, so this should output "-~--" in that case (but doesn't)
    std::string display("----\n");
    for (size_t i = 0; i < word_length; ++i) {
        // Go through all the letters in the guess and compare them to the
        // chosen word
        if (guessed_word[i] == chosen[i]) {
            // If it exactly matches the letter in the corresponding spot of
            // the chosen word, output '*' in that position
            display[i] = '*';
        } else if (chosen.find(guessed_word[i]) != std::string::npos) {
            // If it doesn't match the corresponding position, but it is in
            // the chosen word somewhere else, print '~' in that position
            display[i] = '~';
        }
    }
    std::cout << display;

    won = guessed_word == chosen;
    setScore();
}

void WordRun::setScore() {
    // Scoring is based on two categories: time taken & number of guesses
    // Each of those components can be worth 0 to 150 points
    const int max_category_score = 150;
    // Score starts at 300 and drops by 1 point for every guess or second taken
    // Can't mix types `int` and `time_t`, so casting is necessary
    score = std::max(0, max_category_score - static_cast<int>(duration))
          + std::max(0, max_category_score - guesses);
}
