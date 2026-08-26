#include <iostream>
#include "Array.hpp"

int main() {
    std::cout << "=== Test 1: Empty array ===" << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl << std::endl;
    std::cout << "=== Test 2: Sized array ===" << std::endl;
    Array<int> numbers(5);
    std::cout << "Numbers array size: " << numbers.size() << std::endl << std::endl;

    std::cout << "=== Test 3: Subscript operator ===" << std::endl;
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        numbers[i] = i * 10;
    }
    std::cout << "Numbers: ";
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 4: Deep copy ===" << std::endl;
    Array<int> copy = numbers;
    std::cout << "Before modification:" << std::endl;
    std::cout << "numbers[0] = " << numbers[0] << ", copy[0] = " << copy[0] << std::endl;

    copy[0] = 999;

    std::cout << "After changing copy[0] to 999:" << std::endl;
    std::cout << "numbers[0] = " << numbers[0] << ", copy[0] = " << copy[0] << std::endl;
    if (numbers[0] != copy[0]) {
        std::cout << "SUCCESS: Deep copy works! Original is unchanged." << std::endl;
    } else {
        std::cout << "FAILURE: Shallow copy bug!" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 5: Exception handling ===" << std::endl;
    try {
        numbers[100] = 42;
        std::cout << "ERROR: Should have thrown!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "SUCCESS: Exception caught! Index out of bounds." << std::endl;
    }

    return 0;
}
