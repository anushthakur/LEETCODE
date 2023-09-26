//448.Find all numbers disappeared in an array
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:   //INCOMPLETE SEE LEETCODE SUBMISSIONS FOR ALL POSSIBLE WAYS FOR SOLVING THIS QUESTION
    //trial BRUTE FORCE
    //TC:O(N)
    //SC:O(N)
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        //initialsed check vector with false values
        vector <bool> check (nums.size()+1);

        for(int i=0;i<nums.size();i++)
        {
            check[nums[i]]=true;
        }

        vector <int> result;

        for(int i=1;i<check.size();i++)
        {
            if(check[i]==false) result.push_back(i);
        }

        return result;
        
    }
};

//Sometimes, multiple passes over the input array help find the solution which does not use an additional space