//435. Non-overlapping Intervals

#include<bits/stdc++.h>
using namespace std;
//code with alisha
//https://youtu.be/evA9Z5p16bI
class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        int n=intervals.size();
        int ans=0;
        int previous=0;
        sort(intervals.begin(),intervals.end());
        for(int current=1;current<n;current++)
        {
            if(intervals[current][0]<intervals[previous][1])
            {
                ans++;
                if(intervals[current][1]<=intervals[previous][1])
                {
                    previous=current;
                }
            }
            else
            {
                previous=current;
            }

        }
        return ans;
    }
};