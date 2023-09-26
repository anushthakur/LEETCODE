//2466. Count Ways To Build Good Strings

//CodestorywithMIK (YOUTUBE)

//DYNAMIC PROGRAMMING(RECURSION + MEMOIZATION)


#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
int Z,O,L,H;
const int mod=1e9 + 7;

int function(int l, vector<int>& t)
{
    if(l>H) return 0;
    if(t[l] != -1) return t[l];

    bool addone=false;
    if(l>=L && l<=H)
    {
        addone=true;
    }

    int append_zero=function(l+Z,t);
    int append_one=function(l+O,t);

    return t[l]=(addone + append_zero +append_one)%mod;
}

    int countGoodStrings(int low, int high, int zero, int one) 
    {
       L=low,H=high,O=one,Z=zero;
       vector<int> t(high+1,-1);
       return function(0,t);

    }
};