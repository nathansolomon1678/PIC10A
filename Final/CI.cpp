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
    out << ci_str.get_string();
    return out;
}

bool operator<(const CI_String& ci_str1, const CI_String& ci_str2) {
    return ci_str1.get_string() < ci_str2.get_string();
}

size_t total_chars(const std::string& filename) {
    std::ifstream stream(filename);
    size_t length_in_chars = 0;
    std::string current_line("");
    // If the file is empty or doesn't exist, stream will be in an error
    // state so the while loop will never run, and this will return 0
    while (std::getline(stream, current_line)) {
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
    std::set<CI_String> words;
    std::string current_word;
    while (stream >> current_word) {
        words.insert(CI_String(current_word));
    }
    return words;
}

std::vector<int> uniques_per_line(const std::string& filename) {
    std::ifstream file_stream(filename);
    std::string line("");
    std::vector<int> words_per_line;
    while (std::getline(file_stream, line)) {
        std::istringstream line_stream(line);
        std::set<CI_String> words;
        std::string current_word;
        while (line_stream >> current_word) {
            words.insert(CI_String(current_word));
        }
        words_per_line.push_back(words.size());
    }
    return words_per_line;
}

void print_line_one_info(const std::string& filename) {
    std::ifstream file_stream(filename);
    std::string line1("");
    std::getline(file_stream, line1);
    std::istringstream line1_stream(line1);
    std::map<CI_String, int> occurences;
    std::string current_word;
    while (line1_stream >> current_word) {
        ++occurences[CI_String(current_word)];
    }
    // std::map::iterator points to key-value pairs, so iter->first is a word
    // that appears on the first line of filename, and iter->second is the
    // number of times that that word appears
    for (std::map<CI_String, int>::iterator iter = occurences.begin();
         iter != occurences.end(); ++iter) {
        if (iter->second == 1) {
            std::cout << iter->first << " occurs 1 time\n";
        } else {
            std::cout << iter->first << " occurs " << iter->second << " times\n";
        }
    }
}
