//338. counting bits

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<int> countBits(int n) 
    {
        vector <int> v(n+1);
        // v[0]=0;
        for(int i=1;i<=n;i++)
        {
            if(i%2==0)
            {
                v[i]=v[i/2];
            }
            else
            {
                v[i]=v[i/2] + 1;
            }
        }

        return v;
        
    }
};



/*
class Solution 
{
public:

    //kisi bhi number mein log(x) number of bits hote hain.
    //TC:O(N*log(i))
    vector<int> countBits(int n) 
    {
        vector <int> vect;
        

        for(int i=0;i<=n;i++)
        {
            vect.push_back(__builtin_popcount(i));
        }
        return vect;
    }
};
*/

