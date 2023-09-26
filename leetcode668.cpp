//668. Kth Smallest Number in Multiplication Table

//https://youtu.be/N-7biZf7a0I
//code with alisha

//brute force
//TIMRE COMPLEXITY: O(mn*(log mn))


#include<bits/stdc++.h>
using namespace std;
//TIMRE COMPLEXITY: O(mn*(log k))
//memory limit exceeded
class Solution 
{
public:
    int findKthNumber(int m, int n, int k) 
    {
        priority_queue<int> pq; //by default max heap

        vector<int> vect;

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                vect.push_back(i*j);
            }
        }

        for(int i=0;i<vect.size();i++)
        {
            if(pq.size()<k)
            {
                pq.push(vect[i]);
            }
            else
            {
                if(pq.top()>vect[i])
                {
                    pq.pop();
                    pq.push(vect[i]);
                }
            }
        }
        return pq.top();
    }
};


//================================================================
//BINARY SEARCH

//https://youtu.be/N-7biZf7a0I
class Solution 
{
public:

    int atWhatIndex(int m,int n,int mid)
    {
        int sum=0;
        for(int i=1;i<=m;i++)
        {
            sum+=min(mid/i,n);
        }
        return sum;
    }
    int findKthNumber(int m, int n, int k) 
    {
        int low=1;
        int high=m*n;
        //search space is getting reduced each time,which is being done by the binary search algorithm.

        while(low<=high)
        {
            int mid=(high-low)/2 + low;

            if(atWhatIndex(m,n,mid)<k)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    }
};
