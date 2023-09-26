//1573. Number of Ways to Split a String


//https://youtu.be/TSX__xdfOM8
//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(1)


//wrong for a test case....
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
 public:
    int numWays(string s) 
    {
       long ones=0;
       long n=s.size();

       long MOD=100000007;

       for(char c:s)
       {
           ones+=c-'0';
       }

       if(ones==0) return (int)((((n-1)*(n-2))/2))%MOD;

       if(ones%3!=0) return 0;

       long onethird=ones/3;

       ones=0;

       long ways1=0;
       long ways2=0;

       for(char c: s)
       {
           ones+=c-'0';

           if(ones==onethird) ways1++;
           if(ones==2*onethird) ways2++;
       }
       return (int)((ways1*ways2)%MOD);
    }
};

/*

but this solution is not getting accepted,it is wrong for one test case
s =
"100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000...

output:1097833
expected:401097987


*/