/*
We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.
*/

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int isCap = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if (isupper(word[i]))
                isCap++;
        }
        if (isCap == word.size())
            return true;
        else if (isCap == 0)
            return true;
        else if (isCap == 1 && isupper(word[0]))
            return true;
        else
            return false;
    }
};