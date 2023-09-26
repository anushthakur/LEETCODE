//2484. Count Palindromic Subsequences

#include<iostream>
using namespace std;
#include<vector>


class Solution 
{
public:
/*
    int M=1e9 + 7;
    //here in the question length of subsequence is fixed i.e. 5.

    //trial approach:(incomplete code now)
    //make all subsequences of length 5 and then out of them reject those which aren't palindrome.

    int solve(int idx,int end,int target,string& s)
    {
        //base cases
        if(target==0) 
        {
            if(check()) return 1;
            else return 0;
        }
        if(idx>end || target<0) return 0;

        //take
        int take_idx=

        //not take

    }
    int countPalindromes(string s) 
    {
        //edge case
        if(s.length()<5) return 0;

        int n=s.length()-1;
        int count=5;

       return solve(0,n,count,s);
    }
        
        */


        //OPTIMAL APPROACH
        //https://youtu.be/vW3l7UvYmwQ
        //think then code

        //TIME COMPLEXITY: O(N)
        //SPACE COMPLEXITY: O(1)

        int M=1e9 + 7;
        typedef long long ll;

        int rev(int x)
        {
            if(x<10) return x*10;
            else
            {
                return 10*(x%10) + x/10;
            }
        }

        int countPalindromes(string s) 
        {
            vector <ll> backwardElementCount(10,0);
            vector <ll> forwardElementCount(10,0);
            vector <ll> subsequenceBack(100,0);
            vector <ll> subsequenceFront(100,0);

        //traversing from backwards first***
            for(int i=s.length()-1;i>=0;i--)
            {
                int x = s[i] - '0';
                for(int j=0;j<10;j++)
                {
                    if(backwardElementCount[j]>0)
                    {
                        subsequenceBack[x*10 + j] += backwardElementCount[j];
                    }
                   
                }
                 backwardElementCount[x]++;
            }

            ll ans=0;

            //traversing from forward
            for(int i=0;i<s.length();i++)
            {
                int x=s[i] -'0';
                //remove from the backcount 
                backwardElementCount[x]--;

                for(int j=0;j<10;j++)
                {
                    if(backwardElementCount[j]>0)
                    {
                        subsequenceBack[x*10 + j]-= backwardElementCount[j];
                    }
                }
                
                //calculation
                for(int j=0;j<100;j++)
                {
                    ans += subsequenceFront[j] * subsequenceBack[rev(j)];
                    ans= ans%M;
                }

                //addition to front

                for(int j=0;j<10;j++)
                {
                    if(forwardElementCount[j]>0)
                    {
                        subsequenceFront[j*10 + x] += forwardElementCount[j];
                    }
                }
                forwardElementCount[x]++;
            }
                return ans;
        }
};


