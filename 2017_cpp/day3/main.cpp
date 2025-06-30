#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream file("input.txt");
    if (file.is_open()) {
        file.seekg(0, std::ios::end);
        int size = file.tellg();

        char* input = new char[size];
        input[size] = '\0';
        file.seekg(0);
        file.read(input, size);

        int inputNumber = std::stoi(input);
        int counter {};

        for (int i = 1; i*i <= inputNumber; i += 2) {
            counter++;
            if ((i+2)*(i+2) > inputNumber) {
                std::cout << "input number: " << inputNumber << '\n';
                std::cout << "counter: " << counter << '\n';
                std::cout << "i: " << i << '\n';
                std::cout << "i*i: " << i*i << '\n';
                std::cout << "(inputNumber - i*i) % i: " << (inputNumber - i*i) % i << '\n';
                // std::cout << "Steps: " << (inputNumber - i*i) % (i+1) + i/counter << '\n';
                std::cout << "Steps: " << (inputNumber - i*i) % i + i/counter << '\n';
            }
        }
    }
    else {
        std::cout << "Failed to open file." << '\n';
    }

    return 0;
}
