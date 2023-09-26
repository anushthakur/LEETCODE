//1557. Minimum Number of Vertices to Reach All Nodes

//Doubt: Agar ye ni mention hota -- 'It's guaranteed that a unique solution exists.' toh approach me kya change hota?
//us case me graph me disjoint components honge , so no node can reach every other node
//In that case graph might have multiple components . So we cant reach all nodes, its not possible
//I think in that case we need to find the number of connected components. If it is not 1, then return -1 otherwise use this indegree logic.


//DSU  ?? disjoint set union


//https://youtu.be/7wGJ1nevpnc


#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
 public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector <bool> vect(n,false);
        vector <int> ans;
        for(const auto & x:edges)
        {
            int a=x[0];
            int b=x[1];

            vect[b]=true;
        }

        for(int i=0;i<vect.size();i++)
        {
            if(vect[i]==false)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};