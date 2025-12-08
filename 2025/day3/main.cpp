#include <fstream>
#include <iostream>
#include <string>

int findMax(const std::string& line) {
    int pos;
    for (int i = 0; i < line.length(); ++i) {
        int num = line[i] - '0';
        int max = 0;

        if (num > max) {
            pos = i;
        }
    }
    return pos;
}

int main() {
    std::ifstream file("input.txt");
    std::string line;
    long long total = 0;

    while (std::getline(file, line)) {
        const int len = line.length();
        const int pos1 = findMax(line.substr(0, len - 11));
        std::cout << "pos1: " << pos1 << '\n';
        const int pos2 = findMax(line.substr(pos1, len - pos1 - 10));
        std::cout << "pos2: " << pos2 << '\n';
        const int pos3 = findMax(line.substr(pos2, len - pos2 - 9));
        std::cout << "pos3: " << pos3 << '\n';
        const int pos4 = findMax(line.substr(pos3, len - pos3 - 8));
        std::cout << "pos4: " << pos4 << '\n';
        const int pos5 = findMax(line.substr(pos4, len - pos4 - 7));
        std::cout << "pos5: " << pos5 << '\n';
        const int pos6 = findMax(line.substr(pos5, len - pos5 - 6));
        std::cout << "pos6: " << pos6 << '\n';
        const int pos7 = findMax(line.substr(pos6, len - pos6 - 5));
        std::cout << "pos7: " << pos7 << '\n';
        const int pos8 = findMax(line.substr(pos7, len - pos7 - 4));
        std::cout << "pos8: " << pos8 << '\n';
        const int pos9 = findMax(line.substr(pos8, len - pos8 - 3));
        std::cout << "pos9: " << pos9 << '\n';
        const int pos10 = findMax(line.substr(pos9, len - pos9 - 2));
        std::cout << "pos10: " << pos10 << '\n';
        const int pos11 = findMax(line.substr(pos10, len - pos10 - 1));
        std::cout << "pos11: " << pos11 << '\n';
        const int pos12 = findMax(line.substr(pos11, len - pos11));
        std::cout << "pos12: " << pos12 << '\n';

        const char ch1 = line[pos1] + '0';
        const char ch2 = line[pos2] + '0';
        const char ch3 = line[pos3] + '0';
        const char ch4 = line[pos4] + '0';
        const char ch5 = line[pos5] + '0';
        const char ch6 = line[pos6] + '0';
        const char ch7 = line[pos7] + '0';
        const char ch8 = line[pos8] + '0';
        const char ch9 = line[pos9] + '0';
        const char ch10 = line[pos10] + '0';
        const char ch11 = line[pos11] + '0';
        const char ch12 = line[pos12] + '0';

        std::string joltageStr;
        joltageStr += ch1;
        joltageStr += ch2;
        joltageStr += ch3;
        joltageStr += ch4;
        joltageStr += ch5;
        joltageStr += ch6;
        joltageStr += ch7;
        joltageStr += ch8;
        joltageStr += ch9;
        joltageStr += ch10;
        joltageStr += ch11;
        joltageStr += ch12;

        std::cout << joltageStr << '\n';

        // const long joltage = std::stoi(joltageStr);
        // total += joltage;
    }
    std::cout << "\nTotal: " << total << '\n';
    return 0;
}

        // long max1 = 0;
        // long max2 = 0;
        //
        // for (int i = 0; i < line.length() - 1; ++i) {
        //     long num = line[i] - '0';
        //
        //     if (num > max1) {
        //         max1 = num;
        //         max2 = 0;
        //
        //         for (int j = i+1; j < line.length(); ++j) {
        //             long num2 = line[j] - '0';
        //
        //             if (num2 > max2) {
        //                 max2 = num2;
        //             }
        //         }
        //     }
        // }
