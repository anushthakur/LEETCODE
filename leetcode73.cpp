//73. Set Matrix Zeroes

/*
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    cout<<" no. of rows"<<matrix.size()<<endl;
    cout<<"no. of columns"<<matrix[0].size()<<endl;
    return 0;
}
*/
/*

In the context of vector<vector<int>>, where matrix is a vector of vectors of integers, the conventions for row and column can be interpreted as follows:

matrix.size():

matrix.size() returns the number of rows in the matrix. Each element of the outer vector represents a row, so matrix.size() will give you the total number of rows.
Example: If matrix has a size of 3, it means there are 3 rows in the matrix.
matrix[0].size():

matrix[0].size() returns the number of columns in the first row of the matrix.
Since each element of the outer vector represents a row, matrix[0] represents the first row of the matrix.
matrix[0].size() will give you the number of columns in the first row.
Example: If matrix[0] has a size of 4, it means the first row has 4 columns.

To summarize:

matrix.size() returns the number of rows in the matrix.
matrix[0].size() returns the number of columns in the first row of the matrix.
Remember, in the vector<vector<int>> representation, the outer vector represents the rows, and each inner vector represents a row of the matrix.

*/



//BRUTE FORCE
//Time complexity:O((N*M)*(N + M)) + O(N*M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
//Space Complexity: O(1) as we are not using any extra space.

#include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}


void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // Finally, mark all -1 as 0:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}


//BETTER SOLUTION
//Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
//Space Complexity: O(N) + O(M), where N = no. of rows in the matrix and M = no. of columns in the matrix.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    int row[n] = {0}; // row array
    int col[m] = {0}; // col array

    // Traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark ith index of row wih 1:
                row[i] = 1;

                // mark jth index of col wih 1:
                col[j] = 1;
            }
        }
    }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}







//OPTIMAL SOLUTION
//Time complexity:O(m*n)
//Space complexity:O(1)
class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int row=matrix.size();
        int col=matrix[0].size();
        int col0=1;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    if(j!=0)  matrix[0][j]=0;
                    else col0=0;
                   

                }
            }
        }

        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(matrix[i][j]!=0 && (matrix[i][0]==0 || matrix[0][j]==0))
                {
                    matrix[i][j]=0;
                }
            }
        }

        if(matrix[0][0]==0)
        {
            for(int i=0;i<col;i++)
            {
                matrix[0][i]=0;
            }
        }

        if(col0==0)
        {
            for(int i=0;i<row;i++)
            {
                matrix[i][0]=0;
            }
        }
    }
};