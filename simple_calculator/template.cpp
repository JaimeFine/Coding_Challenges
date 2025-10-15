#include <iostream>

int main() {
    const char* input = "12 34 256 7";
    int numbers[100];
    int count = 0;
    int current = 0;
    bool inNumber = false;

    for (int i = 0; input[i] != '\0'; ++i) {
        char c = input[i];
        if (c >= '0' && c <= '9') {
            current = current * 10 + (c - '0');
            inNumber = true;
        } else if (inNumber) {
            numbers[count++] = current;
            current = 0;
            inNumber = false;
        }
    }

    if (inNumber) {
        numbers[count++] = current;
    }

    // Output
    for (int i = 0; i < count; ++i) {
        std::cout << numbers[i] << " ";
    }

    return 0;
}
