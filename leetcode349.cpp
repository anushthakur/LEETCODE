
//349. Intersection of Two Arrays


//USING HASHING (SET)
//TRIAL
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector <int> ans;
        //use set as it stores unique elements,use unordered as any order is accepted
        unordered_set <int> us1;
        
        for(const auto& x:nums1)
        {
            us1.insert(x);
        }
        unordered_set <int> :: iterator itr1=us1.begin();

         unordered_set <int> us2;
        
        for(const auto& x:nums2)
        {
            us2.insert(x);
        }
        unordered_set <int> :: iterator itr2=us2.begin();

        for(itr1;itr1 != us1.end();itr1++)
        {
            if(us2.find(*itr1)!=us2.end())
            {
                ans.push_back(*itr1);
            }
        }

        return ans;

    }
};

//OPTIMAL SOLUTION
//USING TWO POINTERS AND SORTING AND SET (HASHING)
//https://youtu.be/dTmYy5yCSX8

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int n=  nums1.size();
        int  m=nums2.size();

        set<int>s;
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
                s.insert(nums1[i]);
                i++;
                j++;
            }
        }

        vector<int>ans;
        for (auto t : s)
        {
        ans.push_back(t);
        }
        return ans;
    }
};