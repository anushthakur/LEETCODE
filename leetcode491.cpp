//491. Non-decreasing Subsequences
#include<bits/stdc++.h>
using namespace std;
//codestorywithMIK


class Solution 
{
public:
    int n;
    void solve(int idx,vector<int>& nums,vector<int>& ans,vector<vector<int>>& result)
    {
        //backtracking using for loop(as recusrion and looping can be interchangebly used)
        if(ans.size()>=2)
        {
            result.push_back(ans);
        }
        //har recursion call ka apna ek unordered_set hoga jo duplicacy ko hatayega
        unordered_set <int> st;

        for(int i=idx;i<n;i++)
        {
            //take ki conditions (not take likhne ki zaroorat nhi kyonki vo for loop automatic uske liye check kar lega,sirf jo take kiya tha usko remove karna aniwaarya hai yahan par)
            //yaa toh ans vector jisme combination bana bana kar dekh rhe hain vo empty ho,toh uss case me take karna zaroori hai
            //yaa fir jiko tak kar rhe hain vo element nums array ka non-decreasing ho
            //and*** same recursive stack/recursive call mein agar vo element ek baar already le liya gya hai toh dobara nhi liya jana chaiye otherwise repetition of combination will take place.
        if((ans.empty() || nums[i]>=ans.back()) && st.find(nums[i])==st.end())
            {
                ans.push_back(nums[i]);
                solve(i+1,nums,ans,result); //futher explore 

                //inserting in set because we took this element belonging to nums.
                st.insert(nums[i]);

                //removing(for not_take)
                ans.pop_back();

                
            }
        }

    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        n=nums.size();
        vector<vector<int>> result;
        vector<int>ans;
        solve(0,nums,ans,result);
        return result;
    }
};