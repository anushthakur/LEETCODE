//118. Pascal's Triangle

//https://youtu.be/bR7mQgwQ_o8
//TAKEUFORWARD



//TYPE1 : element at ith row and jth column: OPTIMAL TIME COMPLEXITY : O(denominator i.e. j-1)
//TYPE2 : generate entire row : OPTIMAL TIME COMPLEXITY : O(no. of elements in that row,which is equal to the row no.(1th indexed))
//TYPE3 : generate entire pascal's triangle : OPTIMAL TIME COMPLEXITY :O(no.of elements in that particular row * no. of rows to be generated)  

//APPROACH 1

//Time complexity:O(n^2)
//Space complexity:O()

#include<bits/stdc++.h>
using namespace std; 
class Solution 
{
public:

    vector<int> generateRow(int row)
    {
        vector<int> temp;
        long long res=1; 
        temp.push_back(res); // First element everytime for every row we have already stored in.
        for(int col=1;col<row;col++)
        {
            res*=row-col;
            res/=col;
            temp.push_back(res);
        }
        return temp;


    }
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++)
        {
            ans.push_back(generateRow(i));
        }

        return ans;
    }
};

//APPROACH 2 
//codestorywithMIK

class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        //APPROACH 2

     vector <vector <int> > ans(numRows);

     for(int i=0;i<numRows;i++)
     {
         ans[i]=vector <int> (i+1,1);

         for(int j=1;j<i;j++)
         {
             ans[i][j]=ans[i-1][j] + ans[i-1][j-1];
        }
     }

    return ans;


        
    }
};