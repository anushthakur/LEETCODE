//2790. Maximum Number of Groups With Increasing Length

#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;


class Solution 
{
public:
    //Tech Rhymes
    //https://youtu.be/ZPeuJdg8Zlk
    int maxIncreasingGroups(vector<int>& usageLimits) 
    {
        int groups=0;
        long long currentCount=0;
        long long necessaryCount=1;
        sort(usageLimits.begin(),usageLimits.end());
        for(const auto & x:usageLimits)
        {
            currentCount+=x;

            if(currentCount>=necessaryCount)
            {
                groups++;
                necessaryCount+=groups+1;
            }
        }
        return groups;
    }
};


/*
//TRIAL TLE (figure out?)
class Solution 
{
public:
    int maxIncreasingGroups(vector<int>& usageLimits) 
    {
        map <int,int> mp;
        for(int i=0;i<usageLimits.size();i++)
        {
            mp[i]=usageLimits[i];
        }

//=================ignore======================
        //int sum=0;
        
        //for(int i=0;i<usageLimits.size();i++)
        //{
        //    sum+=usageLimits[i];
        //}
 //==================================================       
        int max=INT_MIN;
        //only for knowing the size of vector of vectors
        for(const auto& x:mp)
        {
            if(x.second>max)
            {
                max=x.second;
                mp.erase(x.first);
                
            }
        }
        vector<vector<int>> res(max,{max});
        int i=1;
        while(!mp.empty())
        {
            for(const auto& x:mp)
            {
            if(x.second>max)
            {
                max=x.second;
                mp.erase(x.first);
            }
            }
            for(int z=i;z<res.size();z++)
            {
                res[z].push_back(max);
            }
            i++;
        }

        for(int i=0;i<res.size()-1;i++)
        {
             if(res[i+1].size()-res[i].size()!=1) return i+1;
        }

        return 0;
    }
};
*/


