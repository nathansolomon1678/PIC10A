#ifndef _CI_H_
#define _CI_H_

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

/**
 * Converts all A-Z characters in the input string to lowercase
 * @param input the string to be conerted
 * @returns input but lowercase
 */
std::string make_lower(const std::string& input);

/**
 * @class CI_String A case-insensitive wrapper for an std::string
 */
class CI_String {
public:
    /**
     * Constructor for CI_String
     * @param _str the string to store in the CI_String object
     */
    CI_String(const std::string& _str);
    /**
     * Getter for str
     * @returns the (lowercase) string stored in this CI_String object
     */
    const std::string& get_string() const;
    /**
     * Getter for the character count
     * @returns the number of characters in str
     */
    size_t size() const;
private:
    const std::string str;
};

/**
 * Overloads the << operator so that you can easily print a CI_String
 * @param out the output stream, most likely std::cout
 * @param ci_str the CI_String object to be printed
 * @returns the output stream but with ci_str.str appended to it
 */
std::ostream& operator<<(std::ostream& out, const CI_String& ci_str);

/**
 * Overloads the < operator so you can compare two CI_String objects
 * @param ci_str1 the first string to be compared
 * @param ci_str2 the second string to be compared
 * @returns whether ci_str1.str < ci_str2.str
 */
bool operator<(const CI_String& ci_str1, const CI_String& ci_str2);

/**
 * Returns the number of chars in the given file
 * @param filename the name of the file to read
 * @returns the number of characters in that file
 */
size_t total_chars(const std::string& filename);

/**
 * Returns the set of unique words in the given file
 * @param filename the name of the file to read
 * @returns the words in that file, as unique CI_String objects
 */
std::set<CI_String> unique_words(const std::string& filename);

/**
 * Returns a vector indicating the number of unique words on each line
 * @param filename the name of the file to read
 * @returns a vector with the number of unique words on each line, in order
 */
std::vector<int> uniques_per_line(const std::string& filename);

/**
 * Prints info about each of the unique words on the first line of a file
 * @param filename the name of the file to read
 */
void print_line_one_info(const std::string& filename);

#endif  // _CI_H_
