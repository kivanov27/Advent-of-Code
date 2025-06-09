#include <fstream>
#include <iostream>

int main() {
    std::ifstream inputFile("input.txt");
    if (inputFile) {
        inputFile.seekg(0, std::ios::end);
        int size = (int)inputFile.tellg() - 1;

        inputFile.seekg(0);
        char* input = new char[size + 1];
        inputFile.read(input, size);

        int sum = 0;

        for (int i = 0; i < size; ++i) {
            int j = (i + (size / 2)) % size;
            if (input[i] == input[j]) {
                sum += input[i] - '0';
            }
        }

        std::cout << sum << '\n';
    }

    return 0;
}
