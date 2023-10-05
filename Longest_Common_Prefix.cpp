class Solution {
    private:
    bool allContainsPrefix(vector<string>& strs,string str,int start,int end){
        for(int i=0;i<strs.size();i++){
            for(int j=start;j<=end;j++){
                if(strs[i][j]!=str[j]){
                    return false;
                }
            }
        }
        return true;
    }
    int findMin(vector<string>& strs){
        int min=INT_MAX;
        for(int i=0;i<strs.size();i++){
            if(strs[i].length()<min){
                min=strs[i].length();
            }
        }
        return min;
    }
    string commonPrefix(vector<string>& strs){
        int l=0;
        int h=findMin(strs);
        string prefix;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(allContainsPrefix(strs,strs[0],l,mid)){
                prefix=prefix+strs[0].substr(l,mid-l+1);
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return prefix;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        return commonPrefix(strs);
    }
};