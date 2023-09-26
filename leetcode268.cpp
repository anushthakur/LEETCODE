//268.missing number
#include<vector>
#include<iostream>
using namespace std;
class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int x=0;
        int i;
        for(i=0;i<nums.size();i++)
        {
            x^=(nums[i]^i);
        }
        x^=i;
        return x;
    }
};

/*
class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        //trial
        int n=nums.size();
        int sum=n*(n+1)/2;
        int s=0;
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
        }
        
        //accumulate() function does the same as we took out sum of all elements of array by using a loop. 
        if(accumulate(nums.begin(),nums.end(),0)!=sum)return sum-s;
        else return 0;
    }
};
*/