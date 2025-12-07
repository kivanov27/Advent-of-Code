#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream file("input.txt");
    std::string line;
    long total = 0;

    while (std::getline(file, line)) {
        int max1 = 0;
        int max2 = 0;

        for (int i = 0; i < line.length() - 1; ++i) {
            int num = line[i] - '0';

            if (num > max1) {
                max1 = num;
                max2 = 0;

                for (int j = i+1; j < line.length(); ++j) {
                    int num2 = line[j] - '0';

                    if (num2 > max2) {
                        max2 = num2;
                    }
                }
            }
        }

        char max1ch = max1 + '0';
        char max2ch = max2 + '0';
        std::string joltageStr;
        joltageStr += max1ch;
        joltageStr += max2ch;

        std::cout << joltageStr << '\n';

        int joltage;
    }

    std::cout << total << '\n';

    return 0;
}
