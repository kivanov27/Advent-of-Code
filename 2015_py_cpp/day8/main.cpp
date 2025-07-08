#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>

int main() {
    std::ifstream file("input.txt");
    if (file) {
        std::string line;
        unsigned diff = 0;

        while (std::getline(file, line)) {
            if (line.length() < 2) {
                continue;
            }
            unsigned codeLen = line.length();
            int memLen = line.length() - 2;

            // std::regex re_backslash(R"(\\\\)");
            // std::regex re_quote(R"(\\\")");
            std::regex re_hex(R"(\\x[0-9a-fA-F]{2})");
            std::regex re(R"(\\\\|\\\"|\\x[0-9a-fA-F]{2})");
            std::smatch match;

            int count = std::distance(
                std::sregex_iterator(line.begin(), line.end(), re),
                std::sregex_iterator());
            memLen -= count;

            int hexCount = std::distance(
                std::sregex_iterator(line.begin(), line.end(), re_hex),
                std::sregex_iterator());
            memLen -= hexCount * 2;

            diff += codeLen - memLen;

            // debug
            std::cout << "Line: " << line << '\n';
            std::cout << "codeLen: " << codeLen << '\n';
            std::cout << "memLen: " << memLen << '\n';
            std::cout << '\n';
        }

        std::cout << diff << '\n';
    } else {
        std::cerr << "Couldn't open input file" << '\n';
    }

    file.close();
    return 0;
}
