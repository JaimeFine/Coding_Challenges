#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>

void basic_calculate(std::vector<int>& container);
void bracket(std::vector<int>& container);

void arg_parse(std::string input, std::vector<int>& container) {
    bool isNumber = false;
    int current = 0;
    
    // clear(input);

    const char* str = input.c_str();

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            current = current * 10 + (str[i] - '0');
            isNumber = true;
        } else if (
            str[i] == '-' || str[i] == '+' || str[i] == '*' || str[i] == '/' ||
            str[i] == '(' || str[i] == ')' || str[i] == '^'
        ) {
            if (isNumber) {
                container.push_back(current);
                current = 0;
                isNumber = false;
            }
            container.push_back(str[i]);
        } else if (str[i] == ' ') {
            continue;
        } else {
            std::cerr << "character '" << static_cast<char>(str[i]) 
            << "' not recognized!" << std::endl;
            exit(-1);
        }
    }

    if (isNumber) {
        container.push_back(current);
    }
}

void bracket(std::vector<int>& container) {
    for ()
}

void basic_calculate(std::vector<int>& container) {
    bracket(container);

    for (int i = 0; i < container.size(); ++i) {
        if (container[i] == '^') {
            int left = container[i - 1];
            int right = container[i + 1];
            int result =static_cast<int>(pow(left, right));

            container[i - 1] = result;
            container.erase(container.begin() + i, container.begin() + i + 2);
            i -= 1;
        }
    }

    for (int i = 0; i < container.size(); ++i) {
        if (container[i] == '*' || container[i] == '/') {
            int left = container[i - 1];
            int right = container[i + 1];

            if (container[i] == '/' && right == 0) {
                 std::cerr << "Error: Division by zero." << std::endl;
                 exit(-1);
            }

            int result = (container[i] == '*') ? left * right : left / right;

            container[i - 1] = result;
            container.erase(container.begin() + i, container.begin() + i + 2);
            i -= 1;
        }
    }

    for (int i = 0; i < container.size(); ++i) {
        if (container[i] == '+' || container[i] == '-') {
            int left = container[i - 1];
            int right = container[i + 1];
            int result = (container[i] == '+') ? left + right : left - right;

            container[i - 1] = result;
            container.erase(container.begin() + i, container.begin() + i + 2);
            i -= 1;
        }
    }
}

int main() {
    std::string input;
    std::vector<int> container;
    container.reserve(1000);

    std::cout << "Please enter your formula, it must not contain space!\n";
    std::cin >> input;

    arg_parse(input, container);
    basic_calculate(container);

    std::cout << container[0] << std::endl;

    return 0;
}