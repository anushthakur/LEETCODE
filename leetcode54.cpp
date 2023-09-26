//54. Spiral Matrix


//TIME COMPLEXITY:O(n^2)
//SPACE COMPLEXITY:O(n)


#include<bits/stdc++.h>
using namespace std;

//codestrorywithMIK
class Solution 
{
 public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int r=matrix.size(); //rows
        int c=matrix[0].size(); //columns

        int dir=0;
        /*
            dir=0 :left to right
            dir=1 :top to down
            dir=2 :right to left
            dir=3 :down to top
        */

        int top=0;
        int down=r-1;

        int left=0;
        int right=c-1;

        vector <int> ans;


        while(top<=down && left<=right)
        {
            if(dir==0)
            {
                //left to right
                //constant row (top)
                for(int i=left;i<=right;i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }

            if(dir==1)
            {
                //top to down
                //constant column (right)
                for(int i=top;i<=down;i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }

            if(dir==2)
            {
                //right to left
                //constant row (down)
                for(int i=right;i>=left;i--)
                {
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }

            if(dir==3)
            {
                //down to top
                //constant column (left)
                for(int i=down;i>=top;i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }


            dir++;

            if(dir==4)
            {
                dir=0;
            }
        }

        return ans;
    }
};