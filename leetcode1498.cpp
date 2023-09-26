
//1498. Number of Subsequences That Satisfy the Given Sum Condition

//https://youtu.be/nxWT_mG-x54

//BRUTE FORCE://TIME COMPLEXITY:O(2^n * n) which is worst

//OPTIMAL APPROACH
#include<bits/stdc++.h>
using namespace std;
//TIME COMPLEXITY:O(n log n)
//SPACE COMPLEXITY:O(1)

#define mod 1000000007
class Solution 
{
 public:
 long help(int x,int y)//O(log n) //binary exponentiation function //y could be as large as the size of the array(i.e. n)
 {
     if(y==1) return x;
     if(y==0) return 1;
     long ans=1;
     if(y%2==0)
     {
         ans=help(x,y/2);
         ans*=ans;
     }
     else
     {
         ans=help(x,y-1);
         ans*=x;
     }
     return ans%mod;
 }
    int numSubseq(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end()); //O(n log n)
        int ans=0;
        int s=0,e=nums.size()-1;

        while(s<=e) //O(n log n)
        { //O(n)
            if(nums[s]+nums[e]<=target)
            {
                ans+=help(2,e-s);
                ans%=mod;
                s++;
            }
            else
            {
                e--;
            }
        }
        return ans;
    }
};