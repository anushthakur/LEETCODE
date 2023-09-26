// 167. Two Sum II - Input Array Is Sorted

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//TRIAL
class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> ans;
        for(int i=0,j=numbers.size()-1;i<j;)
        {
            if(numbers[i]+numbers[j]==target) 
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            else if(numbers[i]+numbers[j]>target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};