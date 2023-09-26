
//350. Intersection of Two Arrays II


//Follow up:

//What if the given array is already sorted? How would you optimize your algorithm?
//What if nums1's size is small compared to nums2's size? Which algorithm is better?
//What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?







//https://youtu.be/XZ6ZL1Qg6og

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
 public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size()>nums2.size())
        {
            intersect(nums2,nums1);
        }

        vector<int> ans;
        unordered_map <int,int> umap;

        for(const auto& x:nums1) //bigger array ko map mein daalenge 
        {
            umap[x]++;
        }

        for(const auto& x:nums2) //because the elements those will be common will be the minimum common of both of them ,example 1,1,1,2 aur 1,3,1 mein ans will be 1,1 and not 1,1,1.
        {
            if(umap[x]>0)
            {
                ans.push_back(x);
                umap[x]--;
            }
        }

        return ans;

    }
};




class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int n=  nums1.size();
        int  m=nums2.size();
        vector<int> ans;
        
        int i=0,j=0;
        
        while(i<n && j<m)
        {
            if(nums1[i] > nums2[j])
            {
                j++;
            }
            else if(nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }

    
        return ans;
    }
};