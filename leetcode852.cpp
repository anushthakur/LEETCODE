//852. Peak Index in a Mountain Array
#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int l=0;
        int r=arr.size()-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;

            if(arr[mid]>arr[mid+1]) 
            {
                if(arr[mid]>arr[mid-1]) return mid;
                else r=mid-1;
            }
            else
            {
                l=mid+1;
            }
            
        }
        return 0; //non void function does not return in all cases
    }
};