#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt");

    if (inputFile.is_open()) {
        std::string range;
        long long total = 0;

        while (std::getline(inputFile, range, ',')) {
            std::istringstream iss(range);
            long long num1, num2;
            char dash;

            if (iss >> num1 >> dash >> num2 && dash == '-') {

                for (long long i = num1; i <= num2; ++i) {
                    const std::string numStr = std::to_string(i);
                    const unsigned length = numStr.length();
                    // std::cout << "Number: " << numStr << " | Number length: " << length << '\n';

                    for (int j = 1; j <= length / 2; ++j) {
                        const std::string seq = numStr.substr(0, j);
                        const int seqLength = seq.length();
                        bool invalid = true;
                        // std::cout << "Sequence: " << seq << " | Sequence length: " << seqLength << '\n';

                        for (int k = j; k <= length - seqLength; k += seqLength) {
                            if (length % seqLength != 0) {
                                invalid = false;
                                break;
                            }

                            // std::cout << "Comparing " << seq << " and " << numStr.substr(k, seqLength) << '\n';
                            if (seq != numStr.substr(k, seqLength)) {
                                invalid = false;
                                // std::cout << "invalidating" << '\n';
                                break;
                            }
                        }

                        if (invalid) {
                            // std::cout << i << '\n';
                            total += i;
                            break;
                        }
                    }
                    // std::cout << '\n';
                }
            }
        }
        std::cout << "Total: " << total << '\n';
    }

    return 0;
}
