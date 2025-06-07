#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("input.txt");
    if (inputFile) {
        inputFile.seekg(0, std::ios::end);
        int size = inputFile.tellg();

        inputFile.seekg(0);
        char* input = new char[size];
        inputFile.read(input, size);

        int sum = 0;

        for (int i = 0; i < size; ++i) {
            if (i + 1 == size) {
                if (input[i] == input[0]) {
                    sum += input[i];
                }
            }
            else {
                if (input[i] == input[i+1]) {
                    sum += input[i];
                }
            }
        }

        std::cout << sum << '\n';
    }

    return 0;
}
