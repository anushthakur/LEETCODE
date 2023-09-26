//997. Find the Town Judge

#include<bits/stdc++.h>
using namespace std;
//codestorywithMIK
//APPROACH 1
class Solution 
{
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int>indegree(n+1,0);
        vector<int>outdegree(n+1,0);

         for(int i=0;i<trust.size();i++)
         {
             outdegree[trust[i][0]]+=1;
             indegree[trust[i][1]]+=1;
         }

         for(int i=1;i<n+1;i++)
         {
             if(indegree[i]==n-1 && outdegree[i]==0) return i;
         }
         return -1;
        
    }
};

//APPROACH 2
class Solution 
{
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int>v(n+1,0);
        for(int i=0;i<trust.size();i++)
        {
            //The town judge trusts nobody,so jo trust kar rha hai vo toh bilkul humara ans nhi hoga
           v[trust[i][0]] -=1;
           //aur jis par trust ho rha hai,possibility hai ki vo ans ho sakta hai
           v[trust[i][1]] +=1;
        }

        for(int i=1;i<v.size();i++)
        {
            if(v[i]==n-1) return i;
        }
        return -1;
    }
};




/*
class Solution 
{
public:
    //trial wrong(not fully understood question)....[[1,2],[2,3]] for this output should be -1 and not 3
    //TC:O(N)
    //SC:O(N)
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int>v(n+1,-1);
        for(int i=0;i<trust.size();i++)
        {
            v[trust[i][0]]=trust[i][1];
        }
        for(int i=1;i<v.size();i++)
        {
            if(v[i]==-1) return i;
        }
        return -1;
    }
};
*/