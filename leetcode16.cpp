//16. 3Sum Closest

#include<bits/stdc++.h>
using namespace std;
class Solution 
{

    //code with alisha
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());

        
        int diff=INT_MAX;
        int ans=0;

        for(int i=0;i<nums.size();i++)
        {   
            int s=i+1;int e=nums.size()-1;

             while(s<e) 
            {
                if(nums[i] + nums[s] + nums[e] == target) return target;

                if(abs((nums[i] + nums[s] + nums[e])-target) < diff)
                {
                    diff=abs((nums[i] + nums[s] + nums[e])-target);
                    ans=nums[i] + nums[s] + nums[e];
                }

                if(nums[i] + nums[s] + nums[e] < target)
                {
                    s++;
                }
                else 
                {
                    e--;
                }


            }
        }

       
       return ans;
    }
};