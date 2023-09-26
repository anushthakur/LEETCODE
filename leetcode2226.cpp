//2226.Maximum candies allocated to k children

#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
//cherry coding (revise)
    long cal(int mid,vector<int>& v)
    {
        long count=0;
        for(int i=0;i<v.size();i++)
        {
            count+=v[i]/mid;
        }
        return count;
    }
    int maximumCandies(vector<int>& candies, long long k) 
    {
        
        int r=*max_element(candies.begin(),candies.end());
       
        int l=0;
        
        
        while(l<r)
        {
            int mid=(l+r+1)/2; //why?

          long check=cal(mid,candies);

            if(k<=check)
            {
                
                l=mid;
            }
            else 
            {
               
                r=mid-1;
            }
            
        }
    return l;
       

        // a child can get atleast MIN(minimum element present in the array) candies(when k<=size of array)
    }
};