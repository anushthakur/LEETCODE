//2124. Check if All A's Appears Before All B's
#include<bits/stdc++.h>
using namespace std;
//trial
class Solution 
{
public:
    bool checkString(string s) 
    {
        for(int i=1;i<s.length();i++)
        {
            if(s[i]-s[i-1]<0) return false;
        }
        return true;
    }
};