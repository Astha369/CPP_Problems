#include <iostream>
#include <string>

// Problem: Checking for Substring
bool isSubstring(const std::string& str, const std::string& sub) {
    return str.find(sub) != std::string::npos;
}

int main() {
    std::string str = "Hello, World!";
    std::string sub = "World";

    if (isSubstring(str, sub)) {
        std::cout << "'" << sub << "' is a substring of '" << str << "'." << std::endl;
    } else {
        std::cout << "'" << sub << "' is not a substring of '" << str << "'." << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>

// Problem: Checking for Subsequence
bool isSubsequence(const std::string& str, const std::string& sub) {
    int i = 0, j = 0;

    while (i < str.length() && j < sub.length()) {
        if (str[i] == sub[j]) {
            j++;
        }
        i++;
    }

    return (j == sub.length());
}

int main() {
    std::string str = "abcde";
    std::string sub = "ace";

    if (isSubsequence(str, sub)) {
        std::cout << "'" << sub << "' is a subsequence of '" << str << "'." << std::endl;
    } else {
        std::cout << "'" << sub << "' is not a subsequence of '" << str << "'." << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>

// Problem: Checking for Palindrome
bool isPalindrome(const std::string& str) {
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

int main() {
    std::string str = "racecar";

    if (isPalindrome(str)) {
        std::cout << "'" << str << "' is a palindrome." << std::endl;
    } else {
        std::cout << "'" << str << "' is not a palindrome." << std::endl;
    }

    return 0;
}
