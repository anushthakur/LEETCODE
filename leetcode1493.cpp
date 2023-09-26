//1493. Longest Subarray of 1's After Deleting One Element

#include<bits/stdc++.h>
using namespace std;

//CODING SAMURAI'S
//https://youtu.be/Jzy1COg8a34

class Solution 
{
public:
    int longestSubarray(vector<int>& nums) 
    {
            int head=0;
            int tail=0;
            int countElementsToBeDeleted=0;
            int length=0;

            for(head;head<nums.size();head++)
            {
                if(nums[head]==0) countElementsToBeDeleted++;

                while(countElementsToBeDeleted>1)
                {
                    if(nums[tail]==0) countElementsToBeDeleted--;

                    tail++;
                }

                length=max(length,(head-tail));
            }
            return length;

    }
};


/*
//half code(trial) //wrong
class Solution 
{
public:
    int longestSubarray(vector<int>& nums) 
    {
        //int deleteIdx=-1;

        //base
        if(nums.size()==1) return 0;

        int index=-1;
        int countOne=0;
        int maxCount=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1) countOne++;
            else
            {
                if(countOne>=maxCount)
                {
                    maxCount=countOne;
                    index=i;
                    countOne=0;
                }
            }
        }
        if(index==-1) return nums.size()-1;
        else 
        {
            for(int i)
        }
    }
};
*/