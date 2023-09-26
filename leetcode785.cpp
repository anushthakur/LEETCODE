//785. Is Graph Bipartite?


//YOUTUBE(codestorywithMIK)

// https://youtu.be/NeU-C1PTWB8

#include<bits/stdc++.h>
using namespace std;
class Solution 
{
 public:

    bool checkBipartiteDFS(vector<vector<int>>& graph,int currNode,vector<int>& color,int currColor)
    {
        color[currNode]=currColor; //color kardiya current node ko

        //ab jate hain adjacent nodes par
        for(const int & x:graph[currNode])
        {
            if(color[x]==color[currNode]) return false;

            if(color[x]==-1)
            {
                //means never colored(never visited)
                int colorOfx = 1 - color[currNode];

                if(checkBipartiteDFS(graph,x,color,colorOfx)==false) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
       vector <int> color (graph.size(),-1); //no node coloured in the start
       //red = 1
       //green = 0

       for(int i=0;i<graph.size();i++)
       {
           if(color[i]==-1) 
           {
            if(checkBipartiteDFS(graph,i,color,1)==false) return false;
           }
       }
       return true;
    }
};