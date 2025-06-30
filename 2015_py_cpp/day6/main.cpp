#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    bool grid[1000][1000] = {};

    std::ifstream file("input.txt");
    file.seekg(0, std::ios::end);
    int size = file.tellg();
    char* input = new char[size];
    file.seekg(0);
    file.read(input, size);
    std::istringstream iss(input);
    std::string line;

    while (iss >> line) {
        int x1, y1, x2, y2;
        if (sscanf(line.c_str(), "%*s %d,%d %*s %d,%d", &x1, &y1, &x2, &y2) == 4) {
            std::cout << "Parsed: " << x1 << ", " << y1 << " -> " << x2 << ", " << y2 << '\n';
        }
        else {
            std::cout << "Failed to parse line." << '\n';
        }
    }

    file.close();

    return 0;
}
