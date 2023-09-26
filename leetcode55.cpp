//55. Jump Game

#include<iostream>
#include<vector>
using namespace std;

/*
//solution of a different question(when you can only jump the distance equal to the element on which we are)
class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int a;
        for(int i=0;i<=nums.size()-1;)
        {
            if(i==nums.size()-1) return true;
            a=i;
            i=i+nums[i];
            if(i==a) return false;
        }
        return false;
    }
};
*/

//but here in this question each element signifies the at most distance we can jump,that means if we wish we can jump lesser than that in order to reach the last index.


//https://youtu.be/EgMPjWliYGY
//code with alisha
class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
            int index=nums.size()-1;

            for(int i=nums.size()-1;i>=0;i--)
            {
                if(i+nums[i]>=index) index=i;
            }

            if(index==0) return true;
            else return false;
    }
};
