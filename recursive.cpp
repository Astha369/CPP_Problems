// Problem Statement:
// Write a C++ program to find the sum of natural numbers up to a given positive integer using recursion.


// Solution:
#include <iostream>

// Function to calculate the sum of natural numbers up to n using recursion
int sumOfNaturalNumbers(int n) {
    if (n <= 0) {
        return 0;
    } else {
        return n + sumOfNaturalNumbers(n - 1);
    }
}

int main() {
    int num;
    std::cout << "Enter a positive integer: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    int sum = sumOfNaturalNumbers(num);

    std::cout << "Sum of natural numbers up to " << num << " is " << sum << std::endl;

    return 0;
}
