#include <iostream>
#include <fstream>
#include <string>

int main() {
    if (std::ifstream inputFile ("input.txt"); inputFile.is_open()) {
        std::string line;
        unsigned int dial = 50;
        unsigned int totalZeroes = 0;

        while (std::getline(inputFile, line)) {
            const char dir = line[0];
            const unsigned int times = std::stoi(line.substr(1));
            const unsigned int full = times / 100;
            const unsigned int rem = times % 100;

            totalZeroes += full;

            if (dir == 'R') {
                if (rem > 0 && dial + rem >= 100) totalZeroes++;
                dial = (dial + rem) % 100;
            }
            else if (dir == 'L') {
                if (rem > 0 && dial != 0 && rem >= dial) totalZeroes++;
                dial = (dial + 100 - rem) % 100;
            }
            std::cout << dial << "\n\n";
        }

        std::cout << "Total zeroes: " << totalZeroes << '\n';
    }

    return 0;
}