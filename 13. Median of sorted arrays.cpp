class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       
       int i,j;
        double med;
        vector<int> num;
        for(auto v:nums1)
          num.push_back(v);
        for(auto v:nums2)
          num.push_back(v);
        
        sort(num.begin(),num.end());
              if(num.size()%2==0)
        {
            i=num.size()/2;
            j=i-1;
            med=(num[i]+num[j])/2.0;
        }
        else 
        {
            i=num.size()/2;
            med=num[i];
        }
        return med;
  
    }
};
