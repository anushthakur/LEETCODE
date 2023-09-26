//35. Search Insert Position
#include<vector>
using namespace std;

class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int l=0;
        int r=nums.size()-1;
        int mid;
        while(l<=r)
        {
            mid=l+(r-l)/2;

            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        if(nums[mid]<target) return mid+1;
        else return mid;
    }
};