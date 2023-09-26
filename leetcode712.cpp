//712. Minimum ASCII Delete Sum for Two Strings


#include<iostream>
#include<string.h>
using namespace std;
//CODESTORYWITHMIK
class Solution 
{
public:
    int t[1001][1001];
    int m,n;

    int solve(string& s1,string& s2,int i,int j)
    {
        
        //base cases
        
        if(i>=m && j>=n) return 0;

        if(t[i][j]!=-1) return t[i][j]; //check if result for this sub problem has already been calculated

        if(i>=m) return t[i][j]=s2[j] + solve(s1,s2,i,j+1);
        else if(j>=n) return t[i][j]=s1[i] + solve(s1,s2,i+1,j);
        if(s1[i]==s2[j]) return t[i][j]=solve(s1,s2,i+1,j+1);

    //two options
        int delete_s1_i= s1[i] + solve(s1,s2,i+1,j);
        
        int delete_s2_j= s2[j] + solve(s1,s2,i,j+1);

        return t[i][j]=min(delete_s1_i,delete_s2_j);
    }

    int minimumDeleteSum(string s1, string s2) 
    {
        m=s1.length();
        n=s2.length();
        memset(t,-1,sizeof(t));
        return solve(s1,s2,0,0);

    }
};