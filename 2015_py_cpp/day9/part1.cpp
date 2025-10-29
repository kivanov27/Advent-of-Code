#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

int main() {
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Couldn't open input file." << '\n';
        return 1;
    }
    std::string line;
    std::map<std::string, bool> locs;

    while (std::getline(file, line)) {
        char loc1[20];
        char loc2[20];
        int dist;

        if (sscanf(line.c_str(), "%s to %s = %d", loc1, loc2, &dist) == 3) {
            std::string loc1Str = loc1;
            std::string loc2Str = loc2;

            if (locs.count(loc1Str) == 0) {
                locs[loc1Str] = false;
            }
            if (locs.count(loc2Str) == 0) {
                locs[loc2Str] = false;
            }
        }
    }

    for (const auto& [k, v] : locs) {
        std::cout << k << " " << v << '\n';
    }

    file.close();

    return 0;
}
