/* Leetcode challenge solution by Tanushree Aggarwal
  Given a pattern and a string "s", find if s follows the same pattern.
   Return "true" if there is a bijection between the "letter pattern" and string "s", else return "false"

Constraints:
1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.


Examples:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Input:pattern = "abba", s = "dog cat cat fish"
Output: false

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false

Input: pattern = "abba", s = "dog dog dog dog"
Output: false
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m;
        vector<string> word;
        int i=0;
        string temp="";
        while(i<s.size())
        {
            if(s[i] == ' ')
            {
                word.push_back(temp);
                temp="";
            }
            else
            {
                temp+=s[i];
            }
            i++;
        }
        word.push_back(temp);
        if(word.size()!=pattern.size())
        {
            return false;
        }
        set<string> st;
        for(int i=0;i<pattern.size();i++)
        {
            if(m.find(pattern[i])!=m.end())
            {
                if(m[pattern[i]]!=word[i])
                {
                    return false;
                }
            }
            else
            {
                if(st.count(word[i])>0)
                {
                    return false;
                }
                st.insert(word[i]);
                m[pattern[i]]=word[i];
            }
            
        }
        return true;
    }
};
