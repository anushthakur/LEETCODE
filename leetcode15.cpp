//15. 3Sum

//takeuforward
//https://youtu.be/onLoX6Nhvmg

#include<bits/stdc++.h>
using namespace std;

//*************MOST OPTIMAL ************************************
//TAKE U FORWARD (view all approaches)
//https://youtu.be/DhFh8Kw7ymk
class Solution 
{
public:
vector<vector<int>> ans;
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum>0)
                {
                    k--;
                }
                else if(sum<0)
                {
                    j++;
                }
                else
                {
                    vector<int> temp ={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;

                }
            }

        }
        return ans;
    }
};

