//First element to occur k times


#include<bits/stdc++.h>
using namespace std;

//wrong look at the expected output
class Solution
{
    public:
    int firstElementKTime(int a[], int n, int k)
    {
        unordered_map <int,int> um;
        for(int i=0;i<n;i++)
        {
            um[a[i]]++;
        }
        
        for(const auto & x:um)
        {
            if(x.second >= k) return x.first;
        }
        return -1;
    }
};

//correct

class Solution
{

 public:
    int firstElementKTime(int a[], int n, int k)
    {
        unordered_map <int,int> um;
        for(int i=0;i<n;i++)
        {
            um[a[i]]++;
            
            if(um[a[i]]>=k) return a[i];
        }
        
     
        return -1;
    }
};