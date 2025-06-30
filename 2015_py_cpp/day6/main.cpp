#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

int main() {
    int grid[1000][1000] = {};
    std::ifstream file("input.txt");

    if (file) {
        std::string line;

        while (std::getline(file, line)) {
            char command[10];
            int x1, y1, x2, y2;

            if (sscanf(line.c_str(), "%9[^0-9] %d,%d %*s %d,%d", command, &x1, &y1, &x2, &y2) == 5) {
                if (std::strcmp(command, "turn on ") == 0) {
                    for (int i = x1; i <= x2; ++i) {
                        for (int j = y1; j <= y2; ++j) {
                            grid[i][j]++;
                        }
                    }
                }
                else if (std::strcmp(command, "turn off ") == 0) {
                    for (int i = x1; i <= x2; ++i) {
                        for (int j = y1; j <= y2; ++j) {
                            if (grid[i][j] > 0) {
                                grid[i][j]--;
                            }
                        }
                    }
                }
                else if (std::strcmp(command, "toggle ") == 0) {
                    for (int i = x1; i <= x2; ++i) {
                        for (int j = y1; j <= y2; ++j) {
                            grid[i][j] += 2;
                        }
                    }
                }
            }
        }
    } 
    else {
        std::cerr << "Failed to open input file" << '\n';
    }

    int sum = 0;

    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {
            sum += grid[i][j];
        }
    }

    std::cout << sum << '\n';

    file.close();

    return 0;
}
