#include <fstream>
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::ifstream file("input.txt");
    if (file) {
        std::string line;
        unsigned charDiff = 0;

        while (std::getline(file, line)) {
            unsigned length = line.length();
            if (line.length() < 2) {
                continue;
            }
            unsigned actualLength = line.length() - 2;

            std::regex re_backslash(R"(\\\\)");
            std::regex re_quote(R"(\\\")");
            std::regex re_hex(R"(\\x[0-9a-fA-F]{2})");
            std::smatch match;

            if (std::regex_search(line, match, re_backslash)) {
                actualLength -= match.size();
            }
            if (std::regex_search(line, match, re_quote)) {
                actualLength -= match.size();
            }
            if (std::regex_search(line, match, re_hex)) {
                actualLength -= match.size() * 3;
            }

            std::cout << "line: " << line << '\n';
            std::cout << "lenght: " << length << '\n';
            std::cout << "actualLen: " << actualLength << '\n';
            std::cout << '\n';

            charDiff += length - actualLength;
        }

        std::cout << charDiff << '\n';
    }
    else {
        std::cerr << "Couldn't open input file" << '\n';
    }


    file.close();
    return 0;
}
