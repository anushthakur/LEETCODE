//81. Search in Rotated Sorted Array II
//PROGRAMMING TUTORIALS
#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
  public:
 bool search(vector<int>& nums, int target) 
 {
        
       int s=0,l=nums.size()-1;
    while(s<=l)
    {
        int mid=(s+l)/2;

        if(target==nums[mid]) return true;

        //to check whether mid element belongs to left sorted array
        else if(nums[s]<nums[mid])
        {
            if(target>=nums[s] && target<nums[mid])
            {
                l=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        //to check whether mid element belongs to right sorted array
        else if(nums[s]>nums[mid])
        {
            if(target>nums[mid] && target<=nums[l])
            {
                s=mid+1;
            }
            else
            {
                l=mid-1;
            }
        }
        else s++; //reducing the search space when not sure to which part the mid belongs to 
    }
        //nums[mid] was never equal to target throughout the while condition then returning -1
        return false;
 }
};
int main()
{   Solution obj;
vector <int> vect{4,4,4,0,4,4,4};
 bool g=obj.search(vect,0);
 if(g==true) cout<<"exists";
 else cout<<"doesn't exist";
  
    return 0;
}