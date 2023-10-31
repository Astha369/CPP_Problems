class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0, len = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]==' ') count=0;
            else{
                count++;
                len = count;
            }
        }
        return len;
    }
};
