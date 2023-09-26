//980. Unique Paths III

#include<vector>
#include<iostream>
using namespace std;

//CODESTORYWITHMIK
class Solution 
{
 public:

 //can move in four directions down,top,left,right

 //down: row will increase by 1 unit and column stays the same i.e.{1,0}.
 //top: row will decrease by 1 unit and column stays the same i.e.{-1,0}.
 //left: row will remain the same and column will decrease by 1 unit i.e.{0,-1}.
 //right: row will remain the same and column will increase by 1 unit i.e.{0,1}.

 vector<vector<int>> directions {{1,0},{-1,0},{0,-1},{0,1}};

 int result;

int walkablecells;

    void backtrack(vector<vector<int>>& grid,int m,int n,int i,int j,int count)
    {
        //base conditions
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==-1) return;

        if(grid[i][j]==2) 
        {
            if(count==walkablecells)
            {
                result++;
            }
            return;
        }
        //===========================

        grid[i][j]=-1;

        for(vector<int>& dir:directions)
        {
            int new_i=i+dir[0];
            int new_j=j+dir[1];

            backtrack(grid,m,n,new_i,new_j,count+1);
        }

        grid[i][j]=0;


    }


    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int m=grid.size(); //no. of rows
        int n=grid[0].size(); //no. of columns

        //to calculate the start cell row and col indexes
        //also calculating total no. of walkable cells
        result=0;
        walkablecells=0;
        int start_i=0; //let
        int start_j=0; //let
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0) walkablecells++;
                if(grid[i][j]==1) 
                {
                    start_i=i; 
                    start_j=j;
                }
            }
        }
        walkablecells += 1; //as starting cell is also walkable and must be included
        int count=0;
        backtrack(grid,m,n,start_i,start_j,count);

        return result;
    }
};