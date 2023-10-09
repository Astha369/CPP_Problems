#include <iostream>
#include <typeinfo>
using namespace std;

/*

I have made two functions:
1. Converting String to Integer
2. Converting Integer to Roman

without using any in-built function

*/

int stringToInt(string s)
{
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ans = ans * 10 + (int(s[i]) - 48);
    }
    return ans;
}

string intToRoman(int n)
{
    string stdRomans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int romanValues[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string ans = "";

    for (int i = 0; i < 13; ++i)
    {
        while (n >= romanValues[i])
        {
            ans = ans + stdRomans[i];
            n = n - romanValues[i];
        }
    }

    return ans;
}

int main()
{
    string s;
    cout <<"Enter a number"<< endl;
    cin>>s;
    cout<<"Datatype of your input: " <<typeid(s).name()<<endl;
    int x = stringToInt(s);
    cout<<"Converted to Integer: "<<x<<", datatype: "<<typeid(x).name()<<endl;
    string r = intToRoman(x);
    cout<<"Converted to Romans: "<<r<<endl;
    return 0;
}