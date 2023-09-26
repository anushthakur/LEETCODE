//509. Fibonacci Number

//codestorywithMIK
#include<vector>
#include<iostream>
using namespace std;

//https://youtu.be/UhxNiImCzdY?list=PLpIkg8OmuX-JhFpkhgrAwZRtukO0SkwAt

//BASIC RECURSION
//TIME COMPLEXITY: O(2^n)
class Solution 
{
 public:
    int fib(int n) 
    {
        //jis variable/parameter par recursion chal rha hai,uski valid smallest value base condition mein define karte hain.
        if(n==0) return 0;
        if(n==1) return 1;

        return fib(n-1) + fib(n-2);
    }
};

//DYNAMIC PROGRAMMING 
//TIME COMPLEXITY: O(2^n) check??

class Solution 
{
 public:
    int solve(int* t,int n)
    {

        //base case
        if(n<=1) return n;
        
        if(t[n]!=-1) return t[n];

        return t[n]=solve(t,n-1) + solve(t,n-2);
    }


 //jitne variables changing hote hain utne hi dimensions ki DP array lagti hai memoization mein.
 //here only one variable i.e. n is changing,so memoization dp array will also be one dimensional.

    //repeating subproblems hone se memoization karna optimal hai.

   

   

    int fib(int n) 
    {
         int t[n+1]; //n+1 size taaki outofbounds kabhi na jaye,aur indexing 0 se hoti hai aur humey toh n values store karani hai vo bhi aise ki jo index hai vahi n ho,so n+1 hi lena padega.

          for(int i=0;i<n+1;i++) t[i]=-1;

          //or

          //vector<int>dp(n+1,-1);
          return solve(t,n);
    }
};


//BOTTOM UP APPROACH 
//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(n)

class Solution 
{
 public:
   int fib(int n) 
    { 
        if(n<=1) return n;

        vector <int> t(n+1,-1);
        t[0]=0;
        t[1]=1;

        //t[i] means ith fibonacci number(state definition),which also means that we need to return t[n] as our answer as t[n] accordingly means nth fibonacci number.

        for(int i=2;i<=n;i++)
        {
            t[i]=t[i-1]+t[i-2];
        }

        return t[n];
    }
};


//SPACE COMPLEXITY MINIMIZATION/OPTIMIZATION

//SPACE COMPLEXITY:O(1)

// (chances hain space complexity kam karne ke as jo ith state hai vo 2 values par depend kar rhi hai (i-1)th aur (i-2)th par,toh poori array banane ki zaroorat nhi).Somehow bas 2 variables mein last two values store karani hai for every i.



class Solution 
{
 public:
   int fib(int n) 
    { 
          if(n<=1) return n;

          int c;
          int a=0,b=1;

          for(int i=1;i<n;i++) //n =5 hai toh 4 iteration mein hi kaam ho jayega.(Ek iteration kam lagegi)
          {
              c=a+b;
              a=b;
              b=c;
          }
          return c;
    }
};

