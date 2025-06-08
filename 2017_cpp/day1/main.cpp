#include <fstream>
#include <iostream>

int main() {
    std::ifstream inputFile("input.txt");
    if (inputFile) {
        inputFile.seekg(0, std::ios::end);
        int size = inputFile.tellg();

        inputFile.seekg(0);
        char* input = new char[size];
        inputFile.read(input, size);

        int sum = 0;

        for (int i = 0; i < size - 1; ++i) {
            int j = (i + ((size - 1) / 2)) % size;
            std::cout << "i: " << i << "   input[i]: " << input[i] << '\n';
            std::cout << "j: " << j << "   input[j]: " << input[j] << '\n';
            if (input[i] == input[j]) {
                std::cout << "Add i: " << input[i] << '\n';
                sum += input[i] - '0';
                std::cout << "Sum: " << sum << '\n';
            }
        }

        std::cout << sum << '\n';
    }

    return 0;
}
