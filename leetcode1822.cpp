//1822. Sign of the Product of an Array
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int countofminus=0;
    int arraySign(vector<int>& nums) 
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0 )return 0;
            
            else if(nums[i]<0)
            {
                countofminus++;
            }
            
        }
        if(countofminus%2==0) return 1;
        else return -1;
    }
};