//240. Search a 2D Matrix II

#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY:O(R+C) {In worst case equal to row count + column count}
class Solution 
{
public:
  //https://youtu.be/LOpgS4jkVzU
  //coding decoded

    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m=matrix.size();
        int n=matrix[0].size();

        //edge case
        if(m==0 || n==0) return false;

        //TWO POINTERS
        int row=m-1;
        int col=0;
        while(row>=0 && col<n)
        {
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) 
            {
                row--;
            }
            else
            {
                col++;
            }
        }
        return false;
    }
};



/*
//TRIAL 
class Solution 
{
public:
int rows;
int cols;

    bool solve(vector<vector<int>>& matrix,int target)
    {
        int top=0;
        int bot=rows-1;
        int mid;

        while(top<bot)
        {
            int mid=top+(bot-top)/2;

            if(matrix[mid][cols-1]==target) return true;
            else if(matrix[mid][cols-1]>target)
            {
                bot=mid-1;
            }
            else if(matrix[mid][cols-1]<target)
            {
                top=mid+1;
            }
           
        }
      int searchR=top;

        int l=0;
        int r=cols-1;
        while(l<r)
        {
            int middle=l+(r-l)/2;
            if(matrix[top][middle]==target) return true;
            else if(matrix[top][middle]>target)
            {
                r=middle-1;
            }
            else if(matrix[top][middle]<target)
            {
                if(l==r)
                {
                    break;
                }
                 l=middle+1;
            }
            

        }

        int searchC=l;
            int s=0;
            int e=rows-1;


            while(s<=e)
            {
                int m=s+(e-s)/2;

                if(matrix[m][searchC]==target) return true;

                else if(matrix[m][searchC]>target)
                {
                    e=m-1;
                }
                else
                {
                    s=m+1;
                }
            }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        rows=matrix.size();
        cols=matrix[0].size();
        return solve(matrix,target);
    }
};
*/