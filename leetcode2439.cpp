//2439.minimize maximum of array

/*
vector<int> foo(100, 5);
sort(foo.begin(), foo.end());        // Case 1
sort(std:begin(foo), std::end(foo)); // Case 2
*/

/*
//Max or Maximum element can be found with the help of *max_element() function provided in STL
//SYNTAX: *max_element (first_index, last_index);
*/


//*************************************OPTIMAL SOLUTION**************************************************
//YOUTUBE(CodestorywithMIK)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution 
{
  public:

    bool isValid(int expected_max,vector<int>& nums )
    {   
        vector<long long>arr(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(arr[i]>expected_max) return false;
            long long buffer=expected_max-arr[i];
            arr[i+1]=arr[i+1]-buffer;

        }
        return(arr[nums.size()-1]<=expected_max);


    }
    int minimizeArrayValue(vector<int>& nums) 
    {
        int minL=nums[0];
        int minR=*max_element(begin(nums),end(nums));
        int result=nums[0];

        while(minL<=minR)
        {
            int mid_expected_max=minL + (minR-minL)/2;
            if(isValid(mid_expected_max,nums))
            {
                result=mid_expected_max;
                minR=mid_expected_max-1;
            }
            else
            {
                minL=mid_expected_max+1;
            }
        }
        return result;
    }
};


int main()
{
    vector<int> vect{3,7,1,6};
    Solution obj;
    int res=obj.minimizeArrayValue(vect);
    cout<<"The minimum value possible of maximum element of the given array is :"<<res;
    return 0;
}