
//======================================================================================================
//CODESTORYWITHMIK

#include<bits/stdc++.h>
using namespace std;

//Bhaiya,could you please help me find out what mistake I have done here...

class Solution 
{
public:
    vector<vector<int>> ans;

    void solve(int idx,int opt,int n,int k,vector<int>& ds)
    {
        //base condition
        if(idx>=k)
        {
            if(opt<=n)
            {
                ans.push_back(ds);
            }
            return;
        }
//take
        ds.push_back(opt);
        solve(idx+1,opt+1,n,k,ds);
//not take
        ds.pop_back();
        solve(idx,opt+1,n,k,ds);

    }

    vector<vector<int>> combine(int n, int k) 
    {
        vector<int>ds;
        solve(0,1,n,k,ds);
        return ans;
    }
};

/*
AddressSanitizer:DEADLYSIGNAL
=================================================================
==22==ERROR: AddressSanitizer: stack-overflow on address 0x7ffebd09efc0 (pc 0x00000034d10a bp 0x7ffebd09f090 sp 0x7ffebd09efc0 T0)
==22==ABORTING
*/


//REPLY
/*
If you notice your base case will never meet for secong recursive call solve(idx, opt+1, n, k, ds) 

Because your base case checks only when idx >= k 
And for this recursive call, you are not increasing idx. 
It will never hit base case.

Also, you don’t need idx for tracking.
K and n is enough

Whenever you make recursive calls, always ensure that the in every recursive call, there MUST be something in the parameters that should be in the base case. 
Else it will never stop. 
In your base case you have only used idx ,
However you have not changed it in your 2nd recursive call

*/

//================================================================================================================




//LEETCODE 712  //codestorywithMIK

/*
DOUBT .....
bhaiya,isme aapne 1st base case ke just neeche "already calculated hai ya nhi / memoization array" vala check lagaya if(t[ i ][ j ] != -1) return t[ i ][ j ]; , par vo 2nd aur 3rd base cases ke pehle lagaya hai, toh kaise pata chalta hai ki kis base case se pehle lagana valid hai...? Kyonki PREDICT THE WINNER vale mein maine check base case ke pehle laga diya tha toh vo kuch OUT OF BOUNDS ki ERROR de rha tha.....


//REPLY


@codestorywithMIK
1 day ago
No no,
You can put the check in the beginning as well. 
Just ensure that , for t[i][j] , i and j should not be out of bound. That’s why we always define size of t a little greater to be on safe side.
If it gives error, you can increase the size of t.
*/