//1011. Capacity To Ship Packages Within D Days


//TAKE U FORWARD
#include<bits/stdc++.h>
using namespace std;

/*
class Solution 
{
public:
    int solve(int mincapacity,vector<int>& weights)
    {
        int days=1;
        int load=0;
        for(int i=0;i<weights.size();i++)
        {
            if(load + weights[i] > mincapacity)
            {
                days=days+1; //next day load hoga new item
                load=weights[i]; //load for fresh day is this new item
            }
            else
            {
                load = load + weights[i]; //same day hi load hoga yani pehle se chala aa rha load + new item ka weight.
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        //TLE
        //BRUTE FORCE (LINEAR SEARCH ON MINCAPACITY) 
        //TC:O(SUM OF ALL WEIGHTS - MAXWEIGHT)*(N)
        //NEAR ABOUT O(N^2)
        int sum=accumulate(weights.begin(),weights.end(),0);
        int maxweight=*max_element(weights.begin(),weights.end());
        for(int i=maxweight;i<=sum;i++)
        {
            if(solve(i,weights)<=days) return i;
        }
        return -1;
    }
};
*/


class Solution 
{
public:
    //BINARY SEARCH ON ANSWERS AND IT'S ONLY POSSIBLE WHEN WE KNOW THE RANGE
    int solve(int mincapacity,vector<int>& weights)
    {
        int days=1;
        int load=0;
        for(int i=0;i<weights.size();i++)
        {
            if(load + weights[i] > mincapacity)
            {
                days=days+1; //next day load hoga new item
                load=weights[i]; //load for fresh day is this new item
            }
            else
            {
                load = load + weights[i]; //same day hi load hoga yani pehle se chala aa rha load + new item ka weight.
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        //binary search on mincapacity
        //***if we take mincapacity lesser than the maximum weight item, then we will never be able to ship it.(whereas in ques. we are to ship all the items.)
        //the mincapacity will always lie between the maximum weighted item and the summation of  the weights of all the items.
        int l=*max_element(weights.begin(),weights.end());
        int r=accumulate(weights.begin(),weights.end(),0);
        int result=0;
        while(l<=r)
        {
            int mid=l + (r-l)/2;

            if(solve(mid,weights)<=days)
            {
                result=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }

        }
        return result;
    }
};
