//442. Find All Duplicates in an Array
//write optimal and brute force too???
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end()); //O(nlogn)
        vector<int>v;
        for(int i=0;i<nums.size()-1;i++) //O(n)
        {
            if(nums[i]==nums[i+1])
            {
                v.push_back(nums[i]);
                i++;
            }
        }
        return v;
    }
};