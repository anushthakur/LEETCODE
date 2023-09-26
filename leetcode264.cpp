//264. Ugly Number II

//https://youtu.be/jRacRh6x4go
#include<bits/stdc++.h>
using namespace std;
//O(n) time complexity:- Dynamic Programming,otherwise brute force was of O(n*log n) with base 2.
class Solution 
{
public:
    int nthUglyNumber(int n) 
    {
        vector <int> t(n+1);
        int i2,i3,i5;
        i2=i3=i5=1;
        t[1]=1;

        for(int i=2;i<=n;i++)
        {
            int i2UglyNo= t[i2]*2;
            int i3UglyNo= t[i3]*3;
            int i5UglyNo= t[i5]*5;

            int minUglyNo=min({i2UglyNo , i3UglyNo ,  i5UglyNo});
            t[i]=minUglyNo;

            if(minUglyNo == i2UglyNo) i2++;
            if(minUglyNo == i3UglyNo) i3++;
            if(minUglyNo == i5UglyNo) i5++;
        }

        return t[n];
    }
};