#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(const T& elem) {
    std::cout << elem << " ";
}

template <typename T>
void increment(T& elem) {
    ++elem;
}

void doubleValue(int& n) {
    n *= 2;
}

void printConstInt(const int& n) {
    std::cout << n << " ";
}

int main() {
    std::cout << "=== Test 1: int array, instantiated template ===" << std::endl;
    int nums[] = {1, 2, 3, 4, 5};
    iter(nums, 5, printElement<int>);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 2: non-const array + modifying function ===" << std::endl;
    iter(nums, 5, doubleValue);
    iter(nums, 5, printElement<int>);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 3: non-const array + template taking T& ===" << std::endl;
    int more[] = {10, 20, 30};
    iter(more, 3, increment<int>);
    iter(more, 3, printElement<int>);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 4: const array + const reference function ===" << std::endl;
    const int constArr[] = {100, 200, 300};
    iter(constArr, 3, printConstInt);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 5: const array + instantiated template ===" << std::endl;
    iter(constArr, 3, printElement<int>);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 6: string array ===" << std::endl;
    std::string words[] = {"Hello", "from", "iter"};
    iter(words, 3, printElement<std::string>);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 7: char array ===" << std::endl;
    char letters[] = {'C', '+', '+'};
    iter(letters, 3, printElement<char>);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 8: empty array (length 0) ===" << std::endl;
    int empty[] = {};
    iter(empty, 0, printElement<int>);
    std::cout << "(nothing printed — correct)" << std::endl;

    return 0;
}
