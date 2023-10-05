class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash[256]={0};
        int isTMapped[256]={0};

        for(int i=0;i<s.length();i++){
            if(hash[s[i]]==0 && isTMapped[t[i]]==0){
                hash[s[i]]=t[i];
                isTMapped[t[i]]=true;
            }
        }

        for(int i=0;i<t.length();i++){
            if((char)hash[s[i]]!=t[i]){
                return false;
            }
        }
        return true;
    }
};