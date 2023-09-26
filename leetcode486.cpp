//486. Predict the Winner

#include<iostream>
#include<vector>
#include<numeric>
#include<string.h>
using namespace std;

//CONCEPT 
//======================================================================================
/*
    (codestorywithMIK) COMMENTED BACK-->
no,we can put check in the beginning of the base cases as well
just ensure that for t[i][j], i and j should not be out of bounds...that is why we always define size of t a littile greater to be on safer side.

*/
//======================================================================================


//CODESTORYWITHMIK

//********************RECURSION WAY-1 (DP)*********************************************
//TIME COMPLEXITY:O(2^N) before memoization
//TIME COMPLEXITY:O(N^2) after memoization
class Solution 
{
public:
//as two parameters are changing,so 2D array for memoization
    int t[21][21];

    int solve(vector<int>& nums,int s,int e)
    {
       // if(t[s][e]!=-1) return t[s][e]; //error
        /*
            Line 9: Char 12: runtime error: index -1 out of bounds for type 'int [21]' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:18:12
        */
        if(s>e) return 0;
        if(s==e) return nums[s];

        if(t[s][e]!=-1) return t[s][e];
        //writing code for pl1
        int take_s= nums[s] + min(solve(nums,s+2,e),solve(nums,s+1,e-1));
        int take_e=nums[e] + min(solve(nums,s,e-2),solve(nums,s+1,e-1));

        return t[s][e]=max(take_s,take_e);

    }


    bool PredictTheWinner(vector<int>& nums) 
    {
        memset(t,-1,sizeof(t));
       /*
        for(int i=0;i<21;i++)
        {
            for(int j=0;j<21;j++)
            {
                t[i][j]=-1;
            }
        }
        */
       int tSum=accumulate(nums.begin(),nums.end(),0);
        int e=nums.size()-1;
       int score_pl1= solve(nums,0,e);
       int score_pl2= tSum-score_pl1;
       return score_pl1>= score_pl2;
    }
};

//**********************************RECURSION WAY-2 (DP)*********************************************