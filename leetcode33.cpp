#include<iostream>
#include<vector>
using namespace std;
//33. Search in Rotated Sorted Array i
//****************************************************************************************
//TRIAL (RUNTIME ERROR)
/*
class Solution 
{
  public:
    int search(vector<int>& nums, int target) 
    {
        int i=1,j=nums.size()-1; 
       
        while(nums[j]<=nums[0])
        {
            j--;

        }
        //cout<<"rotated index is "<<j+1<<endl;
        int s,l;
        if(target<nums[0]) 
        {
            s=j+1;
            l=nums.size()-1;
        }
        else if(target>nums[0]) 
        {
            s=0;
            l=j;
        }
        else return 0;


        while(s<=l)
        {
            int mid=(s+l)/2;
            if(target==nums[mid]) return mid;
            else if(target<nums[mid])
            {
                l=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return -1;
    }
};
int main()
{
    //0,1,2,4,4,4,5,6,6,7 sorted array ,before rotating at 5th index
    vector <int> vect{4,5,6,6,7,0,1,2,4,4};
    Solution obj;
    int f=obj.search(vect,2);
    if(f!=-1) cout<<"Found at "<<f;
    else cout<<"not found";
    return 0;
}
*/


//********************************TAP ACADEMY*****************************

class Solution 
{
  public:
 int search(vector<int>& nums, int target) 
 {
        
       int s=0,l=nums.size()-1;
    while(s<=l)
    {
        int mid=(s+l)/2;

        if(target==nums[mid]) return mid;

        //to check whether mid element belongs to left sorted array
        else if(nums[s]<=nums[mid])
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
        else
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
    }
        //nums[mid] was never equal to target throughout the while condition then returning -1
        return -1;
 }
};
int main()
{
    //0,1,2,4,5,6,7 sorted array ,before rotating at 5th index
    vector <int> vect{7,0,1,2,4,5,6}; //distinct elements
    Solution obj;
    int f=obj.search(vect,2);
    if(f!=-1) cout<<"Found at "<<f;
    else cout<<"not found";
    return 0;
}