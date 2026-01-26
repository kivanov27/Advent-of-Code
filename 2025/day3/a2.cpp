#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream file("input.txt");
    std::string line;
    unsigned long long total = 0;

    while (std::getline(file, line)) {

        // Length
        int len = line.length();

        std:: string numStr = "";
        int maxPos = -1;

        // Loop to lim (limit)
        for (int lim = len - 12; lim < len; ++lim) {
            int max = 0;

            // Loop i from max position to limit
            for (int i = maxPos + 1; i <= lim; ++i) {

                // Extract number
                const int num = line[i] - '0';

                // Assing to max if bigger
                if (num > max) {
                    max = num;
                    maxPos = i;
                }
            }

            numStr += line[maxPos];
        }

        const long long num = std::stoll(numStr); 
        total += num;
        std::cout << num << "\n";
    }

    std::cout << "\nTotal: " << total << '\n';

    return 0;
}
