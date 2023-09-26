//849. Maximize Distance to Closest Person
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
//https://youtu.be/AyQarOkptdw?list=PLEI-q7w3s9gRBsE-5NqYymo8AH1M_k_-E
//CODING DECODED
    int maxDistToClosest(vector<int>& seats) 
    {
        vector <int> left(seats.size(),-1);
        vector <int> right(seats.size(),-1);

        int l=-1;
        for(int i=0;i<seats.size();i++)
        {
            if(seats[i]==1) l=i;

            if(seats[i]==0) left[i]=l;
        }

        int r=-1;
        for(int i=seats.size()-1;i>=0;i--)
        {
            if(seats[i]==1) r=i;

            if(seats[i]==0) right[i]=r;
        }

        int ans=-1;
        int minimum=INT_MAX;
        for(int i=0;i<seats.size();i++)
        {
            if(seats[i]==0)
            {
                minimum=min((left[i]!=-1)?i-left[i]:INT_MAX,(right[i]!=-1)?right[i]-i:INT_MAX);
                ans=max(ans,minimum);
            }
            
        }
        return ans;
    }
};