//1870.Minimum speed to arrive on time

//codestorywithMIK
#include<iostream>
#include<vector>
#include<cmath> //for ceil()  
//ceil(0.0) is 0  //CONCEPT***
using namespace std;

class Solution 
{
public:

    double solve(int minspeed,vector<int>& dist)
    {
        double ans=0.0;
        //ek iteration kam because last train ke baad toh kisi aur train ke liye rukna nhi hai toh integer hour vala koi lafda nhi hai...
        for(int i=0;i<dist.size()-1;i++)
        {
            //time=distance/speed
            double x=double(dist[i])/double(minspeed);
            ans+=ceil(x);
        }
            ans+=double(dist[dist.size()-1])/double(minspeed);
            return ans;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        //given in  QUES. the answer will not exceed 10^7
        int l=1;
        int r=1e7;
        //binary search on speed....***

        int result=-1;
        while(l<=r)
        {
            int mid=l+ (r-l)/2;

            if(solve(mid,dist)<=hour)
            {
                result=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return result;
    }
};