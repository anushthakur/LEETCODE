//34. Find First and Last Position of Element in Sorted Array

#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY:O(log n)

//TRIAL BINARY SEARCH
class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int low=0;
        int high=nums.size()-1;
        int sidx=-1;
        int lidx=-1;
        vector<int>ans(2,-1);

        //for finding sidx 
        while(low<=high)
        {
            int mid=(high-low)/2 + low;

            if(nums[mid]==target)
            {
                sidx=mid;
                high=mid-1;
            }

            if(nums[mid]>target)
            {
                high=mid-1;
            }
            if(nums[mid]<target)
            {
                low=mid+1;
            }
            
        }
        //starting index hi nhi mila toh ending index kya khaak milega
        if(sidx==-1) return ans;


        //for finding lidx 
        
        //don't use sidx + 1 , because in case like this where you need to search let say 10 in array 1,4,8,10 ,so here occurrence is only once so [3,3] would be answer,if you start low as sidx+1 then it will go out of bounds i.e. while condition will be false and you will never enter the loop and in that case you will end up returning [3,-1] which is wrong.
        low=sidx;
        high=nums.size()-1;

        while(low<=high)
        {
            int mid=(high-low)/2 + low;

            if(nums[mid]==target)
            {
                lidx=mid;
                low=mid+1;
            }

            if(nums[mid]>target)
            {
                high=mid-1;
            }
            if(nums[mid]<target)
            {
                low=mid+1;
            }
          
        }

        ans[0]=sidx;
        ans[1]=lidx;
        return ans;

    }
};