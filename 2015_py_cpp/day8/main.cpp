#include <fstream>
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::ifstream file("input.txt");
    if (file) {
        std::string line;

        while (std::getline(file, line)) {
            unsigned length = line.length();

            std::regex re_backslash("\\");

            std::cout << line << '\n';
            std::cout << "Length: " << length << '\n';
        }
    }
    file.close();
    return 0;
}
