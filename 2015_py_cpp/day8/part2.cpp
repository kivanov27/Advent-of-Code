#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream file("input.txt");
    if (file) {
        std::string line;
        unsigned diff = 0;

        while (std::getline(file, line)) {
            if (line == "") continue;
            std::string newLine = "\"";

            for (int i = 0; i < line.length(); ++i) {
                if (line[i] == '\\') {
                    newLine.push_back('\\');
                    newLine.push_back('\\');
                }
                else if (line[i] == '\"') {
                    newLine.push_back('\\');
                    newLine.push_back('\"');
                }
                else {
                    newLine.push_back(line[i]);
                }
            }
            newLine.push_back('\"');

            unsigned codeLen = line.length();
            unsigned memLen = newLine.length();

            diff += memLen - codeLen;

            // debug
            std::cout << "Line: " << line << '\n';
            std::cout << "New line: " << newLine << '\n';
            // std::cout << "codeLen: " << codeLen << '\n';
            // std::cout << "memLen: " << memLen << '\n';
            std::cout << '\n';
        }

        std::cout << diff << '\n';
    } else {
        std::cerr << "Couldn't open input file" << '\n';
    }

    file.close();
    return 0;
}
