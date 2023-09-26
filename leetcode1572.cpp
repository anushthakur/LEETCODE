//1572. Matrix Diagonal Sum

#include<bits/stdc++.h>
using namespace std;

//https://youtu.be/5yF2HkQXuSo

//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(1)

class Solution 
{
 public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int sum=0;
        int n=mat.size();
        for(int i=0;i<n;i++)
        {
            sum+=mat[i][i] + mat[i][n-i-1];
        }
        if(n%2) sum-=mat[n/2][n/2];
        return sum;
    }
};