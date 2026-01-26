#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream file("input.txt");
    std::string line;
    long long total = 0;

    while (std::getline(file, line)) {
        const int len = line.length();
        int joltage[12];
        int c = 0;
        int pos = 0;

        for (int n = len - 12; n <= len; ++n) {
            int max = 0;
            int i = pos;

            while (i < n) {
                const int num = line[i] - '0';
                if (num > max) {
                    max = num;
                    pos = i;
                }
                ++i;
            }

            std::cout << "pos: " << c << ", val: " << max << '\n';

            joltage[c] = max;
            c++;
        }
    }

    std::cout << "\nTotal: " << total << '\n';
    return 0;
}
