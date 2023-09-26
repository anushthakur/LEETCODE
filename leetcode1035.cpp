//1035. Uncrossed Lines //IMP****
//solve 1036 and 72

//codestorywithMIK
//https://youtu.be/eCNwbEznRZE


//TLE
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

//Dynamic Programming
class Solution 
{
    public:

        int x,y;
        int m[501][501]; //Memoization
        int fun(int i,int j,vector<int>& nums1, vector<int>& nums2)
        {
            if(i>=x || j>=y) return 0;

            if(m[i][j]!=-1) return m[i][j];

            if(nums1[i]==nums2[j]) return m[i][j]= 1+ fun(i+1,j+1,nums1,nums2);

            else
            {
                int i_fixed=fun(i,j+1,nums1,nums2);
                int j_fixed=fun(i+1,j,nums1,nums2);

                return m[i][j]=max(i_fixed,j_fixed);
            }

        }


        int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
        {
            x=nums1.size();
            y=nums2.size();
            memset(m,-1,sizeof(m)); //#include<cstring>
            return fun(0,0,nums1,nums2);
        }
};