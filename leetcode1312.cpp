//1312. Minimum Insertion Steps to Make a String Palindrome


//codestorywithMIK
//https://youtu.be/99S-xuAbwoc


//why is it a question of dynamic programming?
//two choices each time (here in this ques) + we need to find the minimum steps
//recursion + optimization


#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

//BY RECURSION
class Solution 
{
  public:
    int solve(string & s,int i,int j)
    {
        if(i>=j) return 0;

        else if(s[i]==s[j])
        {
            return solve(s,i+1,j-1);
        }
        else
        {
            return (1+min(solve(s,i+1,j),solve(s,i,j-1)));
        }
    }

    int minInsertions(string s) 
    {
        int n=s.length();
        return solve(s,0,n-1);
        
    }
};

//BY DP
class Solution 
{
  public:
  int t[501][501]; //memoization
    int solve(string & s,int i,int j)
    {
        if(t[i][j]!=-1) return t[i][j];

        if(i>=j) return 0;

        
        else if(s[i]==s[j])
        {
            return t[i][j]=solve(s,i+1,j-1);
        }
        else
        {
            return t[i][j]=(1+min(solve(s,i+1,j),solve(s,i,j-1)));
        }
    }

    int minInsertions(string s) 
    {
        int n=s.length();
         memset(t,-1,sizeof(t));
        return solve(s,0,n-1);
       
        
    }
};

int main()
{
    Solution obj;
   cout<< obj.minInsertions("zzazz");
    return 0;
}