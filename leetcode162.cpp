//162. Find Peak Element
#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
//FRAZ for explaination
    int findPeakElement(vector<int>& nums) 
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) //as we are comparing mid and mid+1 so we need to ensure that there are atleast two elements tp compare with,l<=r will make the code run for even when there's only one element left
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[mid + 1])
            {
                r = mid; //because mid can be a possible answer and we don't want to miss it
            }
            
            else
            {
                l = mid + 1; //because mid+1 can be a possible answer which we don't intend to miss
            }
            
        }
         return l;
    }
    
};

/*
//FRAZ  //https://youtu.be/xGIF8avlj64
//Codebix  //https://youtu.be/r7U0N2EE_l8
//TRIAL
class Solution 
{
public:
    int findPeakElement(vector<int>& nums) 
    {
        //things to keep in mind: index -1 and n is minus infinity
        //ERROR ********************************************
        //below code out of bounds ki index ke beech mein compare kar rha hai
        int l=0;
        int r=nums.size()-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;

            if(nums[mid]>nums[mid-1])
            {
                if(nums[mid]>nums[mid+1])
                {
                    return mid;
                }
                else
                {
                    l=mid+1;
                }
            }
            else r=mid-1;
        }
        return 0;
    }
};
*/