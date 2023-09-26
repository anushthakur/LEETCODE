//2766. Relocate Marbles




class Solution 
{
 public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) 
    {
        map <int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }

        for(int i=0;i<moveFrom.size();i++)
        {
            int f=moveFrom[i];
            int t=moveTo[i];
            if(mp.find(f)!=mp.end())
            {
                int temp=mp[f];
                mp.erase(f);
                mp[t]+=temp;
            }
        }
        vector <int> ans;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            ans.push_back(it->first);
        }
        return ans;
    }
};


//trial
//TLE on last 3rd case :)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) 
    {
        int max=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>max)
            {
                max=nums[i];
            }
        }
        for(int i=0;i<moveTo.size();i++)
        {
            if(moveTo[i]>max)
            {
                max=moveTo[i];
            }
        }

        vector <bool> v(max,false);

        vector <pair<int,int>> mp;

        for(int i=0;i<nums.size();i++)
        {
            v[nums[i]-1]=true;
        }
        
        for(int i=0;i<moveTo.size();i++)
        {
            mp.push_back({moveFrom[i]-1,moveTo[i]-1});
           
        }

        for(const auto& x:mp)
        {
            v[x.first]=false;
            v[x.second]=true;
        }
        vector <int> ans;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==true) ans.push_back(i+1);
        }
        return ans;
    }
};