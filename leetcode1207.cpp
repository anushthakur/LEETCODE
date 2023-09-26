//1207. Unique Number of Occurrences
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
//trial
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map <int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        for(const auto& x:mp)
        {
           for(const auto& y:mp)
           {
               if(x!=y && (y.second==x.second)) return false;
           }
        }
        return true;
    }
};