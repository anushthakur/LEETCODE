//930. Binary Subarrays With Sum

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
//takeuforward
//prefixsum
unordered_map<int,int>mpp;
//mpp[0]=1; //ERROR BECAUSE In C++, you cannot have executable statements (like assignments) directly inside the class body.

    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        int presum=0;
        int countSubArr=0;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            presum+=nums[i];
            int remove=presum-goal;
            countSubArr+=mpp[remove];
             mpp[presum]+=1; //has to be after the above statements for a reason (case2 like situations)
        }
        return countSubArr;
    }
};

/*
//TRIAL //brute force //T.C. : O(N^2)
class Solution 
{
public:

    int count=0;
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        for(int i=0;i<nums.size();i++)
        {
            int sum=nums[i];
            if(sum==goal) count++;
            for(int j=i+1;j<nums.size();j++)
            {
                sum+=nums[j];
                if(sum==goal)
                {
                  count++;
                }
            }
        }
        return count;
    }
};
*/