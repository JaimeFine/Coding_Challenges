#include <iostream>

class LinearList {
private:
    int* data;
    int capacity;
    int length;

public:
    LinearList(int cap) {
	capacity = cap;
	data = new int[capacity];
	length = 0;
    }

    ~LinearList() {
	delete[] data;
    }

    void insert(int pos, int value) {
	if (length >= capacity) {
	    std::cout << "List is full!" << std::endl;
	    return;
	}
	if (pos < 1 || pos > length + 1) {
	    std::cout << "Invalid position!!!" << std::endl;
	}
	for (int i = length; i >= pos; i--) {
	    data[i] = data[i - 1];
	}
	data[pos - 1] = value;
	length++;
    }

    int search(int value) {
	for (int i = 0; i < length; i++) {
	    if (data[i] == value)
		return i + 1;
	}
	return -1;
    }

    void display() {
	std::cout << "List: ";
	for (int i = 0; i < length; i++) {
	    std::cout << data[i] << " ";
	}
	std::cout << "\n";
    }
};

int main() {
    LinearList list(10);

    list.insert(1, 10);
    list.insert(2, 20);
    list.insert(3, 30);
    list.display();

    list.remove(2);
    list.display();

    int post = list.search(30);
    if (pos != -1)
	std::cout << "Found at position " << pos << std::endl;
    else
	std::cout << "Not found!" << std::endl;

    return 0;
}
