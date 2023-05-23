class Solution {
public:
    int climbStairs(int n) {
        if(n==1||n==2)
          return n;
        int prev = 2;
    int twoprev = 1;
       for(int  i =3;i<=n;i++)
       {
          int curr  = prev + twoprev;
          twoprev = prev;
          prev = curr;        
      }

      return prev;
    }
};
