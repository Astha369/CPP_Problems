class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(auto i=0; i<numRows; i++)
        {
            result.push_back(vector<int>(i+1,1));
            for(auto j=1;j<i;j++)
            result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
        return result ;
    }
};

