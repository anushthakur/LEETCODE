//2248. Intersection of Multiple Arrays


#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


//TRIAL

class Solution 
{
 public:
    vector<int> intersection(vector<vector<int>>& nums) 
    {
        int size=nums.size();

        vector<int> ans;

        unordered_map <int,int> umap;
       

        for(const vector<int>& x: nums)
        {
            for(const int y:x)
            {
                umap[y]++;
            }
        }
        
        for(const auto& t:umap)
        {
            if(t.second % size==0)
            {
                ans.push_back(t.first);
            }
        }

    sort(ans.begin(),ans.end());
        return ans;
    }
};