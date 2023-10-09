#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubstring(string str, string substr) {
        size_t found = str.find(substr);
        return (found != string::npos);
    }

    bool isSubsequence(string str, string subseq) {
        int i = 0, j = 0;
        while (i < str.size() && j < subseq.size()) {
            if (str[i] == subseq[j]) {
                j++;
            }
            i++;
        }
        return (j == subseq.size());
    }

    bool isPalindrome(string str) {
        int left = 0;
        int right = str.size() - 1;

        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
