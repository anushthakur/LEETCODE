//228. Summary Ranges

#include <bits/stdc++.h>
using namespace std;


// TLE

class Solution 
{
public:
    vector<string> ans;
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<bool>v((nums[nums.size()-1])-nums[0]+1,false);   

        for(int i=0;i<nums.size();i++)
        {
            v[nums[i]]=true;
        }
        int j=0;
        while(v[j]!=true) j++;

        for(int i=0;i<v.size()  && j<nums.size();)
        {
            if(v[i]==false)
            {
                if(j==i-1) ans.push_back("j");
                else ans.push_back(to_string(j) + "->" + to_string(i-1));
                
                while(v[j]!=true) j++;
                i=j+1;
            }
            else i++;
        }
        return ans;
    }
};



//====================================================================================================

//https://youtu.be/PyYZCJRAMmY
//codestorywithMIK


//very informative about:  integer overflow and java methods to convert into string and also this problem is similar to sliding window where the size of a window is smallest range possible.



//================Java Implementation:===================================
/*
//A faster way is -->
// ""+int.  res.add(""+start+"->"+nums[i]);

class Solution {
    public List<String> summaryRanges(int[] nums) {
        int n = nums.length;
        List<String> res = new ArrayList<>();
        for(int i=0; i<n; i++) {
            int start = nums[i];
            while(i+1<n && nums[i] + 1 == nums[i+1]) {
                i++;
            }
            if(start != nums[i]) {
                res.add(String.valueOf(start)+"->"+String.valueOf(nums[i]));
            }
            else {
                res.add(String.valueOf(start));
            }
        }
        return res;
    }
}

*/

class Solution 
{
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector <string> ans;

        int n=nums.size();
       

        for(int i=0;i<n;i++)
        {
             int start=nums[i];

            //while(i+1<n && nums[i+1]-nums[i]==1)
            //runtime error: signed integer overflow: 2147483647 - -2147483647 cannot be represented in type 'int'         
            while(i+1<n && nums[i+1]==nums[i]+1)
            {
                i++;
            }
            if(start != nums[i])
            {
                ans.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
            else ans.push_back(to_string(start));
        }
        return ans;
    }
};