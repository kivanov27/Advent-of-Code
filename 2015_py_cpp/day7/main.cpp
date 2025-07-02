#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <cctype>

std::map<std::string, std::string> instructions;
std::map<std::string, int> cache;

bool isNumber(const std::string& s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

int evaluate(const std::string& wire) {
    if(isNumber(wire)) {
        return static_cast<int>(std::stoi(wire));
    }

    if (cache.count(wire)) {
        return cache[wire];
    }

    const std::string& expr = instructions[wire];
    std::smatch match;

    static const std::regex re_binary("(\\w+) (AND|OR) (\\w+)");
    static const std::regex re_shift("(\\w+) (RSHIFT|LSHIFT) (\\d+)");
    static const std::regex re_not("NOT (\\w+)");
    static const std::regex re_direct("(\\w+|\\d+)");

    int result = 0;

    if (std::regex_match(expr, match, re_binary)) {
        int lhs = evaluate(match[1]);
        int rhs = evaluate(match[3]);

        if (match[2] == "AND") {
            result = lhs & rhs;
        }
        else {
            result = lhs | rhs;
        }
    } 
    else if (std::regex_match(expr, match, re_shift)) {
        int lhs = evaluate(match[1]);
        int amount = std::stoi(match[3]);

        if (match[2] == "LSHIFT") {
            result = lhs << amount;
        }
        else {
            result = lhs >> amount;
        }
    } 
    else if (std::regex_match(expr, match, re_not)) {
        result = ~evaluate(match[1]);
    } 
    else if (std::regex_match(expr, match, re_direct)) {
        result = evaluate(match[1]);
    } 
    else {
        std::cerr << "Unrecognized format: " << expr << '\n';
    }

    cache[wire] = result;
    return result;
}

int main() {
    std::ifstream file("input.txt");
    if (file) {
        std::string line;
        std::regex re_line("(.+) -> (\\w+)");

        while (std::getline(file, line)) {
            std::smatch match;
            if (std::regex_match(line, match, re_line)) {
                std::string expr = match[1];
                std::string wire = match[2];
                instructions[wire] = expr;
            }
        }

        int part1 = evaluate("a");
        cache.clear();
        instructions["b"] = std::to_string(part1);
        std::cout << evaluate("a") << '\n';
    }

    file.close();

    return 0;
}
