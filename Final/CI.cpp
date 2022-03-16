#include "CI.h"

std::string make_lower(const std::string& input) {
    std::string copy(input);
    for (char& c : copy) {
        // For each character in the copy of input, see whether it's an
        // uppercase A-Z letter, and if so make it lowercase. Then return
        // the (now all lowercase) copy of input
        if ('A' <= c && c <= 'Z') {
            // c is uppercase if and only if it is in the range from
            // 'A' to 'Z' (inclusive)
            // Now make it lowercase:
            c += 'a' - 'A';
            // Every lowercase letter a-z has an ascii value 32 higher than
            // the corresponding uppercase letter, so adding 'a' -'A'
            // will turn any letter A-Z into the corresponding letter a-z
        }
    }
    return copy;
}

CI_String::CI_String(const std::string& _str) : str(make_lower(_str)) {}

const std::string& CI_String::get_string() const {
    return str;
}

size_t CI_String::size() const {
    return str.size();
}

std::ostream& operator<<(std::ostream& out, const CI_String& ci_str) {
    // Appends the case-insensitive string to the output stream
    out << ci_str.get_string();
    return out;
}

bool operator<(const CI_String& ci_str1, const CI_String& ci_str2) {
    // Allows you to use the less-than operator to compare two CI_String objects
    return ci_str1.get_string() < ci_str2.get_string();
}

size_t total_chars(const std::string& filename) {
    std::ifstream stream(filename);
    size_t length_in_chars = 0;
    std::string current_line("");
    // If the file is empty or doesn't exist, stream will be in an error
    // state so the while loop will never run, and this will return 0. That's
    // what we want, so we don't need to check that the stream is in a valid
    // state before using it
    while (std::getline(stream, current_line)) {
        // For each line in the file, add the number of characters on that line
        // to the running total
        length_in_chars += current_line.size();
        // We also want to count the newline characters, so add one for each
        // line that we read to account for the '\n'
        if (!stream.eof()) {
            // There is a newline character or EOF at the end of every line,
            // but EOF doesn't count as a character
            ++length_in_chars;
        }
    }
    return length_in_chars;
}

std::set<CI_String> unique_words(const std::string& filename) {
    std::ifstream stream(filename);
    // std::set will automatically ignore duplicates
    std::set<CI_String> words;
    std::string current_word;
    while (stream >> current_word) {
        // Iterate through all the words in the file stream -- that is, any
        // strings that are separated by whitespace characters like ' ' or '\n'
        words.insert(CI_String(current_word));
    }
    return words;
}

std::vector<int> uniques_per_line(const std::string& filename) {
    std::ifstream file_stream(filename);
    std::string line("");
    std::vector<int> words_per_line;
    while (std::getline(file_stream, line)) {
        // For each line, create another stream object so that we can split it
        // wherever there are spaces
        std::istringstream line_stream(line);
        std::set<CI_String> words;
        std::string current_word;
        while (line_stream >> current_word) {
            // For each word on the current line, add that to out list, and
            // ignore duplicates
            words.insert(CI_String(current_word));
        }
        // the number of elements of words is the number of unique words on the
        // current line
        words_per_line.push_back(words.size());
    }
    return words_per_line;
}

void print_line_one_info(const std::string& filename) {
    // Start by separating the file by newline characters, put the first piece
    // in another stream object so it can be split by spaces
    std::ifstream file_stream(filename);
    std::string line1("");
    std::getline(file_stream, line1);
    std::istringstream line1_stream(line1);
    // file_stream is now irrelevant; we can just read from line1_stream
    // occurrences is a dictionary where the keys are words that appear on line
    // 1 and their corresponding values are how many times they appear
    std::map<CI_String, int> occurrences;
    std::string current_word;
    while (line1_stream >> current_word) {
        // Read each word and increment its count
        // int defaults to zero, so if it's not yet in the dictionary, this
        // will set its count to one
        ++occurrences[CI_String(current_word)];
    }
    // std::map::iterator points to key-value pairs, so iter->first is a word
    // that appears on the first line of filename, and iter->second is the
    // number of times that that word appears
    for (std::map<CI_String, int>::iterator iter = occurrences.begin();
         iter != occurrences.end(); ++iter) {
        // std::map implements a binary search tree, which can't be randomly
        // accessed by index, and its iterators are weird too, so we can't do
        // a nice for-each loop. This is roughly equivalent to the python code
        // ```for word, count in occurrences:```
        if (iter->second == 1) {
            // If it only occurs once, use singular "time"
            std::cout << iter->first << " occurs 1 time\n";
        } else {
            // Otherwise do the same thing but with the plural, "times"
            std::cout << iter->first << " occurs "
                      << iter->second << " times\n";
        }
    }
}
