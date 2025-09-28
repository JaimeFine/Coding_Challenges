#include <iostream>

// A simple linear list class using dynamic array
class LinearList {
private:
    int* data;      // Pointer to the array storing list elements
    int capacity;   // Maximum number of elements the list can hold
    int length;     // Current number of elements in the list

public:
    // Constructor: initializes the list with a given capacity
    LinearList(int cap) {
        capacity = cap;
        data = new int[capacity]; // Allocate memory for the array
        length = 0;               // Start with an empty list
    }

    // Destructor: frees the allocated memory
    ~LinearList() {
        delete[] data;
    }

    // Inserts a value at a specific position (1-based index)
    void insert(int pos, int value) {
        if (length >= capacity) {
            std::cout << "List is full!" << std::endl;
            return;
        }
        if (pos < 1 || pos > length + 1) {
            std::cout << "Invalid position!!!" << std::endl;
            return;
        }

        // Shift elements to the right to make space
        for (int i = length; i >= pos; i--) {
            data[i] = data[i - 1];
        }

        // Insert the new value
        data[pos - 1] = value;
        length++;
    }

    // Removes the element at a specific position (1-based index)
    void remove(int pos) {
        if (pos < 1 || pos > length) {
            std::cout << "Invalid position!" << std::endl;
            return;
        }

        // Shift elements to the left to fill the gap
        for (int i = pos - 1; i < length - 1; i++) {
            data[i] = data[i + 1];
        }

        length--;
    }

    // Searches for a value and returns its position (1-based index), or -1 if not found
    int search(int value) {
        for (int i = 0; i < length; i++) {
            if (data[i] == value)
                return i + 1;
        }
        return -1;
    }

    // Displays the current list contents
    void display() {
        std::cout << "List: ";
        for (int i = 0; i < length; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
};

// Main function to demonstrate usage
int main() {
    LinearList list(10); // Create a list with capacity 10

    list.insert(1, 10);  // Insert 10 at position 1
    list.insert(2, 20);  // Insert 20 at position 2
    list.insert(3, 30);  // Insert 30 at position 3
    list.display();      // Output: List: 10 20 30

    list.remove(2);      // Remove the element at position 2 (value 20)
    list.display();      // Output: List: 10 30

    int pos = list.search(30); // Search for value 30
    if (pos != -1)
        std::cout << "Found at position " << pos << std::endl;
    else
        std::cout << "Not found!" << std::endl;

    return 0;
}
