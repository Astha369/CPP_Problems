class Solution {
    private:
    std::array<int,256>hash(string s){
        std::array<int,256>hash={0};
        for(int i=0;i<s.length();i++){
            hash[s[i]]++;
        }
        return hash;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<std::array<int,256>,vector<string>>mp;
        for(auto str:strs){
            mp[hash(str)].push_back(str);
        }

        vector<vector<string>>ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};