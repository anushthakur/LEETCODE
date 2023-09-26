#include <iostream>
#include<vector>
using namespace std;
//153. Find Minimum in Rotated Sorted Array
//*******************CODEBIX*************************
class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        int s=0,l=nums.size()-1;
        while(s<l)
        {
            int mid=(s+(l-s)/2);
            if(nums[mid]>nums[l])
            {
                s=mid+1;
            }
            else l=mid; 
        }
        return nums[s];  //return nums[l];
        
    }
};
int main()
{
    
    Solution obj;
    vector <int> vect{7,8,9,1,2,3,5}; //elements are unique
    int r=obj.findMin(vect);
    cout<<"smallest element "<<r;
    
    return 0;
}