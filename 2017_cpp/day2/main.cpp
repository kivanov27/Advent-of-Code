#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

int main() {
    std::ifstream file("input.txt");
    std::string line;
    int sum;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            int x;
            int lowest {};
            int highest {};
            bool isLowestSet = false;

            while (iss >> x) {
                if (!isLowestSet) {
                    lowest = x;
                    isLowestSet = true;
                }

                if (x < lowest) {
                    lowest = x;
                }
                else if (x > highest) {
                    highest = x;
                }
            }

            sum += highest - lowest;
            std::cout 
                << "Lowest: " << lowest 
                << " | Highest: " << highest 
                << " | Sum: " << sum << '\n';
        }
    }
    else {
        std::cout << "Couldn't open file.\n";
    }

    std::cout << "Sum = " << sum << '\n';

    return 0;
}
