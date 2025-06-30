#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::ifstream file("input.txt");
    if (file) {
        std::string line;
        while (std::getline(file, line)) {
            char eval[20];
            char var[10];
            std::sscanf(line.c_str(), "%[^-] -> %s", eval, var);

            std::istringstream iss(eval);
            char* arr[3];

            // fix cause array doesn't always have 3 items
            for (int i = 0; i < 3; ++i) {
                iss >> arr[i];
                std::cout << arr[i] << '\n';
            }
        }
    }

    return 0;
}
