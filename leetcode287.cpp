//287.find the duplicate number

#include<bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        //TC:O(N)
        //SC:O(1)

        //we already know that there is existence of cycle if we represent the array in linked list form.Our goal is to return the start node of the cycle as that is the same node to which multiple other nodes are pointing at(i.e. that's the repeated number).

        //NEETCODE for explaination
        //Ayushi sharma //https://youtu.be/pavdSf5f5pw

        int fast=nums[0];
        int slow=nums[0];

        //do-while loop because initially toh vo dono nums[0] ke barabar hain,i.e. same hain....
        do
        {
            fast=nums[nums[fast]];
            slow=nums[slow];
        } while(fast!=slow);

        slow=nums[0];

        while(fast!=slow)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};



/*
class Solution 
{
public:
//WRONG APPROACH BECAUSE TEST CASES CAN BE LIKE [2,2,2,2,2]
    int findDuplicate(vector<int>& nums) 
    {
        int m=nums.size()-1;
        int cal=m*(m+1)/2;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        return sum-cal;

    }
};
*/