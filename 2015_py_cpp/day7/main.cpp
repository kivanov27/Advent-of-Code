#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>

int main() {
    std::ifstream file("input.txt");
    if (file) {
        std::string line;
        std::map<std::string, int> wires;

        std::regex re_binary("(\\w+) (AND|OR) (\\w+) -> (\\w+)");
        std::regex re_shift("(\\w+) (RSHIFT|LSHIFT) (\\d+) -> (\\w+)");
        std::regex re_not("NOT (\\w+) -> (\\w+)");
        std::regex re_direct("(\\w+|\\d+) -> (\\w+)");

        while (std::getline(file, line)) {
            std::smatch match;

            if (std::regex_match(line, match, re_binary)) {
                if (match[2] == "AND") {
                    wires[match[4]] = wires[match[1]] & wires[match[3]];
                }
                else {
                    wires[match[4]] = wires[match[1]] | wires[match[3]];
                }
            }
            else if (std::regex_match(line, match, re_shift)) {
                if (match[2] == "RSHIFT") {
                    wires[match[4]] = wires[match[1]] >> std::stoi(match[3].str());
                }
                else {
                    wires[match[4]] = wires[match[1]] << std::stoi(match[3].str());
                }
            }
            else if (std::regex_match(line, match, re_not)) {
                wires[match[2]] = !wires[match[1]];
            }
            else if (std::regex_match(line, match, re_direct)) {
                std::cout << match[1] << " -> " << match[2] << '\n';
                std::string src = match[1].str();
                if (std::isdigit(src[0])) {
                    wires[match[2]] = std::stoi(src);
                }
                else {
                    wires[match[2]] = wires[src];
                }
            }
            else {
                std::cerr << "Unrecognized format: " << line << '\n';
            }
        }

        std::cout << "Wire a: " << wires["a"] << '\n';
    }

    file.close();

    return 0;
}
