#include "CI.h"
#include <iostream>
#include <string>

int main()
{
    std::cout << make_lower("hELLo") << '\n';
	
	CI_String s("PIC 10A");
    std::cout << s << '\n';
    std::cout << s.size() << '\n';
    std::cout << (CI_String("CS") < s) << '\n';

    const std::string file = "demo.txt";
    auto char_count = total_chars(file);
    auto line_info = uniques_per_line(file);
    auto words = unique_words(file);

    std::cout << "In " << file << " there are " << char_count << " characters.\n";
    std::cout << "The unique words are:\n";
    for (const auto& w : words) {
        std::cout << w << '\n';
    }
    std::cout << "Line by line, the number of unique words are: ";
    for (auto s : line_info) {
        std::cout << s << ' ';
    }
    std::cout << '\n';
    std::cout << "Line 1 info:\n";
    print_line_one_info(file);

    // when file does not exist
    const std::string bad_file = "no_file.txt";
    auto char_count_bad = total_chars(bad_file);
    auto line_info_bad = uniques_per_line(bad_file);
    auto words_bad = unique_words(bad_file);

    std::cout << "In " << bad_file << " there are " << char_count_bad << " characters.\n";
    std::cout << "The unique words are:\n";
    for (const auto& w : words_bad) {
        std::cout << w << '\n';
    }
    std::cout << "Line by line, the number of unique words are: ";
    for (auto s : line_info_bad) {
        std::cout << s << ' ';
    }
    std::cout << '\n';
    std::cout << "Line 1 info:\n";
    print_line_one_info(bad_file);

    return 0;
}