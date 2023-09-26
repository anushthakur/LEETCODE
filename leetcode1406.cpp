//1406. Stone Game III

#include<bits/stdc++.h>
using namespace std;

//FRAZ
//https://youtu.be/HsY3jFyaePU
class Solution 
{
public:

int dp[50001];
int help(vector<int>& stoneValue,int i)
{
    if(i>=stoneValue.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    else
    {
        int ans=INT_MIN;
        ans=max(ans,stoneValue[i]-help(stoneValue,i+1));
        if(i+1<stoneValue.size()) ans=max(ans,stoneValue[i]+stoneValue[i+1]-help(stoneValue,i+2));
        if(i+2<stoneValue.size()) ans=max(ans,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-help(stoneValue,i+3));
        return dp[i]=ans;
    }
}
    string stoneGameIII(vector<int>& stoneValue) 
    {
        memset(dp,-1,sizeof(dp));
        int Alice=help(stoneValue,0);
        if(Alice>0) return "Alice";
        else if(Alice==0) return "Tie";
        return "Bob";
    }
};