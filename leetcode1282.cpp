//1282. Group the People Given the Group Size They Belong To
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        vector <vector <int> > ans;
        int n=groupSizes.size();
        vector <vector <int> > mp(n+1);

        for(int i=0;i<n;i++)
        {
            int x=groupSizes[i];

            mp[x].push_back(i);

            if(mp[x].size()==x)
            {
                ans.push_back(mp[x]);
                mp[x]={};
            }
        }
        return ans;

    }
};