//217. Contains Duplicate


//BRUTE FORCE (NESTED LOOPS) 
//TIME COMPLEXITY:O(n^2)
//SPACE COMPLEXITY:O(1)



//https://youtu.be/3OamzN90kPg
#include<bits/stdc++.h>
using namespace std;
//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(n)
class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(const auto & x:mp)
        {
            if(x.second>=2) return true;
        }
        return false;
    }
};

//TIME COMPLEXITY:O(n log n)
//SPACE COMPLEXITY:O(1)
class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
          sort(begin(nums),end(nums)); //O(n log n)
          int i=0,j=1;
          for( i,j;i<nums.size()-1 && j<nums.size();i++,j++) //O(n)
          {
              if(nums[i]==nums[j]) return true;
          }
          return false;
    }
};
