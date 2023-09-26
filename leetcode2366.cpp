//2366. Minimum Replacements to Sort the Array

#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:

//codingMohan
//https://youtu.be/ODsnUR_oPsQ

//'nums[i]' & 'x' both are integer and division of 2 integers gives another integer (quotient). So, it will always gives the 'floor' in reality.

//Converting 'x' to double, we make sure that the value of division is a decimal value & hence 'ceil' will work correctly.

    typedef  long long ll; //kis data type ko kya bulane vale hai neeche code mein...
    long long minimumReplacement(vector<int>& nums) 
    {
       //In C++, ceil() is a mathematical function that is used to round a floating-point number up to the nearest integer that is greater than or equal to the original number. It's part of the <cmath> (or <math.h> in C) library, and it stands for "ceiling".
       //function signature is as follows:   double ceil(double x);

        ll ans=0;

        int nxt=INT_MAX;

        for(int j=nums.size()-1;j>=0;j--)
        {
            if(nums[j]<=nxt)
            {
                nxt=nums[j];
                continue;
            }
            else
            {
                ll parts=ceil(nums[j]/double(nxt));
                ans+=parts-1;
                nxt=nums[j]/parts;
            }
        }
        return ans;

    }
};