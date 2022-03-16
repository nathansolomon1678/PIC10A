#ifndef _CI_H_
#define _CI_H_

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

std::string make_lower(const std::string& input);

class CI_String {
public:
    CI_String(const std::string& _str);
    const std::string& get_string() const;
    size_t size() const;
private:
    const std::string str;
};

std::ostream& operator<<(std::ostream& out, const CI_String& ci_str);

bool operator<(const CI_String& ci_str1, const CI_String& ci_str2);

size_t total_chars(const std::string& filename);

std::set<CI_String> unique_words(const std::string& filename);

std::vector<int> uniques_per_line(const std::string& filename);

void print_line_one_info(const std::string& filename);

#endif  // _CI_H_
