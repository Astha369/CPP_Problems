class Solution {
public:
    int reverse(int x) {
        long n=0;
        long p=pow(2,31);
        while(x)
        {
            int d=x%10;
            n=n*10+d;
            x=x/10;
        }
        if(n>=(-p)&&n<=(p-1))
        return n;
        else
        return 0;
        
    }
};
