//70. Climbing Stairs

//codestorywithMIK
//https://youtu.be/6OjGE04Kx_M

// #include<bits/stdc++.h>
#include<iostream>
#include<cstring>
using namespace std;

//Recursion (brute force)
//Time complexity: O(2^n) 
//TLE
class Solution 
{
public:

    int solve(int n)
    {
        if(n<0) return 0;
        if(n==0) return 1; //we have found one valid way

        int one_step=solve(n-1);
        int two_steps=solve(n-2);

        return one_step + two_steps;
    }
    
    int climbStairs(int n) 
    {
        return solve(n);
    }
};


//DP = RECURSION + MEMOIZATION(as there were repeating sub problems)
//top down approach

class Solution 
{
public:
    int t[46];
    int solve(int n)
    {
        if(n<0) return 0;
        if(n==0) return 1; //we have found one valid way
        if(t[n]!=-1) return t[n];

        int one_step=solve(n-1);
        int two_steps=solve(n-2);

        return t[n]=one_step + two_steps;
    }

    int climbStairs(int n) 
    {
        memset(t,-1,sizeof(t));
        return solve(n);

    }
};

//BOTTOM UP APPROACH (chote solution se bade solution ki ore jaa rhe hain)

//BOTTOM UP
class Solution 
{
public:

 int climbStairs(int n) 
    {
        //state definition :-
        //array[i] means number of ways to climb i stairs.
        //that means our final answer requires to return array[n] i.e. no. of ways to climb n stairs.

        if(n<0) return 0;
        if(n==1 || n==2) return n;
         int array[n+1];
         array[0]=0;
         array[1]=1;
         array[2]=2;

         for(int i=3;i<=n;i++)
         {
             array[i]=array[i-1] + array[i-2];
         }
         return array[n];

    }
};


//SPACE OPTIMIZATION

class Solution 
{
 public:

    int climbStairs(int n) 
    {
        if(n<0) return 0;
        if(n==1 || n==2) return n;

        int c;
        int a=1;
        int b=2;

        for(int i=3;i<=n;i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};

