// This program utilizes stack data structure to check if a given string is pallindrome.

#include <iostream>
#include <stack>
#include <string>
#include <cctype>

// Function to remove spaces and convert a string to lowercase
std::string preprocessString(const std::string& str) {
    std::string result;
    for (char c : str) {
        if (!std::isspace(c)) {
            result += std::tolower(c);
        }
    }
    return result;
}

// Function to check if a string is a palindrome
bool isPalindrome(const std::string& str) {
    std::stack<char> charStack;
    std::string processedStr = preprocessString(str);

    // Push characters onto the stack
    for (char c : processedStr) {
        charStack.push(c);
    }

    // Pop characters from the stack and compare with the string
    for (char c : processedStr) {
        if (charStack.top() != c) {
            return false; // Characters do not match, not a palindrome
        }
        charStack.pop();
    }

    return true; // All characters matched, it's a palindrome
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "The string is a palindrome." << std::endl;
    } else {
        std::cout << "The string is not a palindrome." << std::endl;
    }

    return 0;
}
