#include <iostream>
#include <string>
#include <vector>

int arg_parse(std::string input) {
    bool isNumber = false;
    int count = 0;
    int current = 0;
    const char* str = input.c_str();
    int container[250];
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            current = current * 10 + (str[i] - '0');
            isNumber = true;
        } else if (
            str[i] == '-' || str[i] == '+' || str[i] == '*' || str[i] == '/'
        ) {
            isNumber = false;
            current = 0;
            container[count++] = current;
            container[count++] = str[i];
        }
    }

    if (isNumber) {
        container[count++] = current;
    }

    for (int i = 0; i < count; ++i) {
        std::cout << container[i] << " ";
    }

    return 0;
}

int main() {
    std::string input;
    std::cin >> input;
    arg_parse(input);

    return 0;
}