#include <iostream>
#include <string>
#include <cstdlib>

int arg_parse(std::string input) {
    bool isNumber = false;
    int count = 0;
    int current = 0;
    
    // clear(input);

    const char* str = input.c_str();
    int container[250];

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            current = current * 10 + (str[i] - '0');
            isNumber = true;
        } else if (
            str[i] == '-' || str[i] == '+' || str[i] == '*' || str[i] == '/'
        ) {
            if (isNumber) {
                container[count++] = current;
                current = 0;
                isNumber = false;
            }
            container[count++] = str[i];
        } else {
            std::cerr << "character '" << static_cast<char>(str[i]) 
            << "' not recognized!" << std::endl;
            exit(-1);
        }
    }

    if (isNumber) {
        container[count++] = current;
    }

    for (int i = 0; i < count; ++i) {
        if (
            container[i] == '-' || container[i] == '+' ||
            container[i] == '*' || container[i] == '/'
        ) {
            std::cout << static_cast<char>(container[i]) << " ";
        } else
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