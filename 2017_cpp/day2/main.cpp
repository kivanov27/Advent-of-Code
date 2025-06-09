#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::ifstream file("input.txt");
    std::string line;
    int sum = 0;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            int x;
            std::vector<int> numbers;

            while (iss >> x) {
                numbers.push_back(x);
            }

            for (int i = 0; i < numbers.size() - 1; ++i) {
                for (int j = i + 1; j < numbers.size(); ++j) {
                    if (numbers[i] % numbers[j] == 0) {
                        sum += numbers[i] / numbers[j];
                        break;
                    }
                    else if (numbers[j] % numbers[i] == 0) {
                        sum += numbers[j] / numbers[i];
                        break;
                    }
                }
            }
        }
    }
    else {
        std::cout << "Couldn't open file.\n";
    }

    std::cout << "Sum = " << sum << '\n';

    return 0;
}
