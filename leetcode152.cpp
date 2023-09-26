//152. Maximum Product Subarray

//https://youtu.be/hnswaLJvr6g
//TAKEUFORWARD

#include<bits/stdc++.h>
using namespace std;
//TLE
//TIME COMPLEXITY:O(n^2)
class Solution 
{
 public:
    int maxProduct(vector<int>& nums) 
    {
        //edge case
        //if(nums.size()==1) return nums[0];

        long long maxpro=INT_MIN;
        int temp;
        //brute force
        for(int i=0;i<nums.size();i++)
        {
            temp=1;
            for(int j=i;j<nums.size();j++)
            {
                temp*=nums[j];
                if(temp>maxpro) maxpro=temp;
            }
        }
        return maxpro;
    }
};

//https://youtu.be/hnswaLJvr6g
//TIME COMPLEXITY:O(n)
#include<algorithm>
class Solution 
{
public:
    int maxProduct(vector<int>& nums)
    {
        int prefix=1;
        int suffix=1;
        int maxpro=INT_MIN;
    
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;

            prefix*=nums[i];
            suffix*=nums[n-i-1];
            maxpro=max(maxpro,max(prefix,suffix));                  
        }
        return maxpro;
    }
};