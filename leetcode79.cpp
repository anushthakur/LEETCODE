//79.word search




#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Space Complexity: O(L)
Time Complexity: O(M * N * 3^L)

Space Complexity is because of recursion - to store function stack context.
Time Complexity - from every block we go in three adjacent blocks (avoiding the direction we came from). This walk can go for max of L times. So each thred at most goes L length long. -> O(3^L). Now this is applied at each node from main calling function -> O(M * N). Therefore, O(M * N * 3^L).


The time complexity will be O(m*n*3^L)
Where L = length of input word

Because in worst case we will visit each cell (m*n) and from each cell our recursion depth will go as far 3^L

Why not 4^L
Because, we never visit the path where we came from. (If you draw the backtracking/recursion tree, you will notice at any level, 3 Children are allowed since we cannot traverse back to oath from where we came)


*/


//TIME COMPLEXITY: O(M * N * 3^L)
//SPACE COMPLEXITY: O(L)


//BACKTRACKING --->CodestorywithMIK (YOUTUBE)
class Solution 
{
 public:
    int r,c;
    vector <vector <int> > directions{{1,0},{-1,0},{0,1},{0,-1}};

    bool find(vector<vector<char>> & board,int i,int j,int word_idx,string & word)
    {
        if(word_idx==word.size()) return true;

        if(i>=r || j>=c || i<0 || j<0 || board[i][j]=='$') return false;

        if(board[i][j] != word[word_idx]) return false;

        char temp=board[i][j];
        board[i][j]='$';

        for(const auto & dir:directions)
        {
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            if(find(board,new_i,new_j,word_idx+1,word)==true) return true;

        }

        board[i][j]=temp;
        return false;
    }



    bool exist(vector<vector<char>>& board, string word) 
    {
        r=board.size();
        c=board[0].size();

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]==word[0] && find(board,i,j,0,word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};