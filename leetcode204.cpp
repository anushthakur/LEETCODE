//204. Count Primes
#include<bits/stdc++.h>
using namespace std;

//TLE
class Solution 
{
public:
    int countPrimes(int n) 
    {
        //edge cases
        if(n==0 || n==1) return 0;
         if(n==2) return 0;

        int count=1;
        bool flag=false;
        for(int i=3;i<n;i++)
        {
            flag=false;
            for(int j=2;j<i;j++)
            {
                if(i%j==0)
                {
                    flag=true;
                    break;
                } 
                
            }
            if(flag==false)count++;
             
           
        }
        return count;
    }
};

int main()
{
    Solution obj;
    cout<<"Final:"<<obj.countPrimes(10);
    return 0;
}

//***********************************************************************************************
//SIEVE OF ERATOSTHENES
//https://youtu.be/o_fP7U-pTX0
class Solution 
{ //sieve of eratosthenes
public:
    int countPrimes(int n) 
    {
        bool* arr=new bool[n];
        //initialized arr with true
        for(int i=2;i<n;i++)
        {
            arr[i]=true;
        }

        for(int i=2;i*i<n;i++)
        {
            //if already marked false then no need to mark,we can continue
            if(!arr[i]) continue;

            for(int j=i*i;j<n;j+=i)
            {
                arr[j]=false;
            }
        }
        int count=0;
        for(int i=2;i<n;i++)
        {
            if(arr[i]==true) count++;
        }
        return count;
    }
};
