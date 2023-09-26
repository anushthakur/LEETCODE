//1140. Stone Game II

#include<bits/stdc++.h>
using namespace std;
//TIME COMPLEXITY:O(n^3)
class Solution 
{
public:
int n;
int t[2][101][101];
int solve(vector <int> & piles,int person,int i,int M)
{
    if(i>=n) return 0;

    if(t[person][i][M]!=-1) return t[person][i][M];

    int result=(person==1)? -1:INT_MAX;

    int stones=0;

    for(int x=1;x<=min(2*M,n-i);x++)
    {
        stones+=piles[i+x-1];

        if(person==1) //Alice
        {
            result=max(result,stones+solve(piles,0,i+x,max(M,x)));
        }
        else //Bob
        {
              result=min(result,solve(piles,1,i+x,max(M,x)));
        }
    }
    return t[person][i][M]=result;
}
    int stoneGameII(vector<int>& piles) 
    {
        n=piles.size();

        memset(t,-1,sizeof(t));

        return solve(piles,1,0,1);
    }
};