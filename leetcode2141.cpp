//2141. Maximum Running Time of N Computers


//TIME COMPLEXITY:O(m*log(range)) where m=size of batteries vector of integers and range=r-l

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
//codestorywithMIK
typedef long long ll;


bool possible(vector<int>& batteries,ll mid,int n)
{
    ll target_minutes=mid*n;
    ll sum=0;

    for(int i=0;i<batteries.size();i++)
    {
        sum+=min((ll)batteries[i],mid);

        if(sum>=target_minutes) return true;
    }
    return false;
}


    long long maxRunTime(int n, vector<int>& batteries) 
    {
        ll l=*min_element(batteries.begin(),batteries.end());

        ll sum_total_minutes=0;
        for(const int x:batteries)
        {
            sum_total_minutes+=x;
        }

        ll r=sum_total_minutes;

        ll result=0;

        //binary search

        while(l<=r)
        {
            ll mid=l+(r-l)/2;

            if(possible(batteries,mid,n))
            {
                result=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return result;
    }
};




/*trial example test case
//n=4
//[2,1,4,5,6,2]
//expected output=4




//TRIAL (ALL WRONG)
class Solution 
{
public:

long long sum=0;
int curr=0;
int l;
int min;

    long long solve(int n,int size,vector<int>& batteries)
    {
        while(l>=n || min!=0)
        {
            min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(batteries[i]<min)
            {
                min=batteries[i];
            }
        }
        curr=min;
       sum+=min;

       for(int i=0;i<n;i++)
        {
            batteries[i]-=curr;
        }
        for(int j=n;j<l;j++)
        {
            batteries[j-1]=batteries[j];
        }
        l--;

        }
         
          return sum;

    }
    long long maxRunTime(int n, vector<int>& batteries) 
    {
        int size=batteries.size();
        l=batteries.size()-1;
        sort(batteries.begin(),batteries.end(),greater<int>());
        return solve(n,size,batteries);
    }
};
*/