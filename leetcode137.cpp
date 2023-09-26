//137. Single Number II

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
//Code with Alisha
//https://youtu.be/Nt920vgqXyE
public:
    int singleNumber(vector<int>& nums)
    {
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int countZero=0;
            int countOne=0;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j] & (1<<i))
                {
                    countOne++;
                }
                else
                {
                    countZero++;
                }
            }
            if(countOne % 3)
            {
                //set bit of our number as 1
                ans= ans | (1<<i); 

            }

        }
        return ans;
    }
};