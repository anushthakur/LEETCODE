//154. Find Minimum in Rotated Sorted Array ii
//CODEBIX
#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        int s=0,l=nums.size()-1;
        while(s<l)
        {
            int mid=(s+(l-s)/2); //to prevent integer overflow
            if(nums[mid]>nums[l])
            {
                s=mid+1;
            }
            else if(nums[mid]<nums[l]) l=mid; 
            else l--;
        }
        return nums[s];  //return nums[l];
        
    }
};
int main()
{
    Solution obj;
    vector <int> vect{7,7,7,3,3,3,3}; //duplicates
    int r=obj.findMin(vect);
    cout<<"smallest element "<<r;
    return 0;
}