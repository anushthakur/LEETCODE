//920. Number of Music Playlists


//codestorywithMIK
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:

    const int MOD=1e9 + 7;
    long t[101][101];

    long solve(int count_songs,int count_unq_songs,int n,int goal,int k)
    {
        //base case
        if(count_songs==goal)
        {
            if(count_unq_songs==n)
            {
                return t[count_songs][count_unq_songs]=1;
            }
            return 0;
        }

        if(t[count_songs][count_unq_songs]!=-1) return t[count_songs][count_unq_songs];

        long result=0;

        //OPTION 1 : (PLAY A UNIQUE SONG)
        if(count_unq_songs<n)
        {
            result+=(n-count_unq_songs)*solve(count_songs+1,count_unq_songs+1,n,goal,k);
        }

        //OPTION 2 : (REPLAY A  SONG)
        if(count_unq_songs>k)
        {
            result+=(count_unq_songs-k)*solve(count_songs+1,count_unq_songs,n,goal,k);
        }

        return t[count_songs][count_unq_songs]=result%MOD;
    }
    int numMusicPlaylists(int n, int goal, int k) 
    {
        memset(t,-1,sizeof(t));
        return solve(0,0,n,goal,k);
    }
};