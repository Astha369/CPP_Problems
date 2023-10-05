// a cpp program that generates the Fibonacci series up to given input number.

#include <iostream>

int main() {
    int n, t1 = 0, t2 = 1, nextTerm = 0;

    std::cout << "Enter a positive number: ";
    std::cin >> n;

    std::cout << "Fibonacci Series: " << t1 << ", " << t2 << ", ";

    nextTerm = t1 + t2;

    while(nextTerm <= n) {
        std::cout << nextTerm << ", ";
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }

    return 0;
}
