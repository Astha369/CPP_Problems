#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int n = str.size();
        long result = 0;
        bool negative = false;

        // Remove leading whitespaces
        while (i < n && str[i] == ' ') {
            i++;
        }

        // Check for optional sign
        if (i < n && (str[i] == '-' || str[i] == '+')) {
            negative = (str[i] == '-');
            i++;
        }

        // Process digits
        while (i < n && isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
            if (result > INT_MAX) {
                return negative ? INT_MIN : INT_MAX;
            }
            i++;
        }

        return negative ? -result : result;
    }

    string intToRoman(int num) {
        unordered_map<int, string> romanMap = {
            {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"},
            {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"},
            {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"},
            {1000, "M"}
        };

        string result = "";

        for (auto it = romanMap.rbegin(); it != romanMap.rend(); it++) {
            while (num >= it->first) {
                result += it->second;
                num -= it->first;
            }
        }

        return result;
    }
};
