class Solution {
public:
    bool isPalindrome(int x) {
        
        int n1=x;
        unsigned int sum=0;
        if(x<0 || (x%10==0 && x!=0))
            return false;
        else
        {
            while(x!=0)
        {
           sum= sum*10+ x%10;
            x=x/10;            
        }
        if(sum==n1)
            return true;
        else
            return false;
        }
        
    }
};
