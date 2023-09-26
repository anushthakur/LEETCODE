//739. Daily Temperatures

#include<bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        /*
        //BRUTE FORCE (TLE)
        //TC:O(N^2)
        //SC:O(1)
        vector <int> ans(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++)
        {
            for(int j=i+1;j<temperatures.size();j++)
            {
                if(temperatures[j]>temperatures[i])
                {
                    ans[i]=j-i;
                    break;
                }
            }
        }
        return ans;
        */
//============================================================
/*
        //APPROACH 1
        //https://youtu.be/7MIXlgBfr_U
        //code with alisha
        //TC:O(N)
        //SC:O(N)
        stack <int> st; //only to store indices
        vector <int> ans;
        int n=temperatures.size()-1;

        //traversing array from backwards
        for(int i=n;i>=0;i--)
        {
            if(st.empty())
            {
                st.push(i);
                ans.push_back(0);
            }
            else
            {
                while(!st.empty() && temperatures[st.top()]<=temperatures[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                     st.push(i);
                    ans.push_back(0);
                }
                else
                {
                    ans.push_back(st.top()-i);
                    st.push(i);
                }
            }

        }

        reverse(ans.begin(),ans.end());
         return ans;
*/

//===========================================================
    //APPROACH 2
       //TC: O() TLE
       //SC:O(1)

       int n=temperatures.size()-1;
       int hottest=INT_MIN;
       vector <int> ans(temperatures.size(),0);

       for(int i=n;i>=0;i--)
       {
           //to know what's the highest value towards the right
           if(temperatures[i]>=hottest)
           {
               hottest=temperatures[i];
           }
           else
           {
               int check=i+1;
               while(temperatures[check]<=temperatures[i])
               {
                   check=check + ans[check];
               }
               ans[i]=check-i;
           }
       }
        return ans;

    }
};

