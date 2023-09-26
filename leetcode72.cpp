//72. Edit Distance  (IMP QUESTION***)

#include<vector>
#include<iostream>
#include<string.h>
using namespace std;


//TAKEUFORWARD

//***************INCOMPLETE****************************
//WATCH STRIVER'S SOLUTION TO THIS****
//HAS DONE AMAZING OPTIMIZATIONS*****


//For now this only has one basic way,BUT COMPLETE IT IN FUTURE AND ***RESOLVE THIS QUESTION***
class Solution 
{
public:
   

    //OF RECURSION ALONE--->
    //TIME COMPLEXITY:O(3^N * 3^M)
    //SPACE COMPLEXITY:O(N+M) //AUXILIARY STACK SPACE



     //top-down recursion with memoization
     //TIME COMPLEXITY:O(N*M)
    //SPACE COMPLEXITY:O(N*M) //MEMOIZATION ARRAY + O(N+M) //AUXILIARY STACK SPACE
    int solve(int i,int j,string& s1,string& s2,vector<vector<int>>& t)
    {
        //base conditions
        if(i==0) return j;
        if(j==0) return i;

        if(t[i][j]!=-1) return t[i][j];    
        if(s1[i-1]==s2[j-1]) return t[i][j]=solve(i-1,j-1,s1,s2,t);

        //insert,delete,replace
        return t[i][j]=min(1+solve(i,j-1,s1,s2,t),min(1+solve(i-1,j,s1,s2,t),1+solve(i-1,j-1,s1,s2,t)));
    }
    int minDistance(string word1, string word2) 
    {
        int m=word1.length();
        int n=word2.length();
        vector<vector<int>> t(m+1,vector<int>(n+1,-1));
        return solve(m,n,word1,word2,t);
    }
};



//******************BOTTOM-UP (TABULATION)*********************

class Solution 
{
public:
//BOTTOM-UP (TABULATION)
    int minDistance(string word1, string word2) 
    {
        int m=word1.length();
        int n=word2.length();

        vector<vector<int>> t(m+1,vector<int>(n+1,0));

        //base conditions
        for(int i=0;i<=m;i++) t[i][0]=i;
        for(int j=0;j<=n;j++) t[0][j]=j;

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1]) t[i][j]=t[i-1][j-1];
                else
                {
                    t[i][j]=min(1+t[i-1][j],min(1+t[i][j-1],1+t[i-1][j-1]));
                }
            }
        }

        return t[m][n];
    }
};

////M*N MATRIX CAN BE FURTHER SPACE OPTIMIZED(refer takeuforward) //incomplete

//*******************OPTIMAL SOLUTION****************************