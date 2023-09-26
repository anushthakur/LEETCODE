//875. Koko Eating Bananas

#include<bits/stdc++.h>
using namespace std;


//TIME COMPLEXITY:O(N*logN)
//SPACE COMPLEXITY:O(1)

class Solution 
{
public:
//takeuforward

//wrong answer: piles = [805306368,805306368,805306368]  h = 1000000000 Output=1  Expected=3

/*

//correction

class Solution 
{
public:
//takeuforward

    long cal(int mid,vector <int> & piles)
    {
        long count=0;
        for(int i=0;i<piles.size();i++)
        {
            count+=ceil(double(piles[i])/double(mid));
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int ans=0;
        int MaX=INT_MIN;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]>MaX) MaX=piles[i];
        }


    

        //applying binary search on answers i.e. v vector
        int l=1;
        int r=MaX;

        while(l<=r)
        {
            int mid=l+(r-l)/2;
            long hours=cal(mid,piles);

            if(hours<=h)
            {
                ans=mid;
                r=mid-1;
               
            }
            else 
            {
                l=mid+1;
            }
             
        }

    return ans;
    }
};
*/


    int cal(int mid,vector <int> & piles)
    {
        long count=0;
        for(int i=0;i<piles.size();i++)
        {
            count+=ceil(double(piles[i])/double(mid));
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int MaX=INT_MIN;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]>MaX) MaX=piles[i];
        }


        
        //vector <int> v(MaX);

        /*
        for(int i=0;i<v.size();i++)
        {
           v[i]=i+1;
            
        }
        */

        //applying binary search on answers i.e. v vector
        int l=1;
        int r=MaX;

        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int hours=cal(mid,piles);

            if(hours<=h)
            {
                r=mid-1;
               
            }
            else 
            {
                l=mid+1;
            }
             
        }

    return l;
    }
};

//==========================================================

class Solution 
{
public:
//takeuforward

//memory limit exceeded
    int cal(int mid,vector <int> & piles,vector <int>& v)
    {
        int count=0;
        for(int i=0;i<piles.size();i++)
        {
            count+=ceil(double(piles[i])/double(mid));
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int MaX=INT_MIN;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]>MaX) MaX=piles[i];
        }
        vector <int> v(MaX);

        for(int i=0;i<v.size();i++)
        {
            v[i]=i+1;
            
        }

        //applying binary search on answers i.e. v vector
        int l=1;
        int r=MaX;

        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int hours=cal(mid,piles,v);

            if(hours<=h)
            {
                r=mid-1;
               
            }
            else 
            {
                l=mid+1;
            }
             
        }

    return l;
    }
};