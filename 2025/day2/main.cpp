#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt");

    if (inputFile.is_open()) {
        std::string range;
        int total = 0;

        while (std::getline(inputFile, range, ',')) {
            std::istringstream iss(range);
            int num1, num2;
            char dash;

            if (iss >> num1 >> dash >> num2 && dash == '-') {
                for (int i = num1; i <= num2; ++i) {
                    const std::string numStr = std::to_string(i);

                    if (numStr[0] == '0') {
                        std::cout << numStr << '\n';
                        total += i;
                    }
                    if (numStr.length() % 2 == 0 && numStr.substr(0, numStr.length() / 2) == numStr.substr(numStr.length() / 2)) {
                        std::cout << numStr << '\n';
                        total += i;
                    }
                }
            }
        }

        std::cout << '\n' << "Total: " << total << '\n';
    }

    return 0;
}
