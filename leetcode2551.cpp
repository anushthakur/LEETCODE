//2551. Put Marbles in Bags


#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

//CODESTORYWITHMIK
class Solution 
{
public:
    long long putMarbles(vector<int>& weights, int k) 
    {
        int n=weights.size();
        int m=n-1;
        vector<int> pairSum(m,0);
        for(int i=0;i<m;i++)
        {
            pairSum[i]=weights[i] + weights[i+1];
        }
        sort(pairSum.begin(),pairSum.end());

        long maxSum=0;
        long minSum=0;

        for(int i=0;i<k-1;i++)
        {
            minSum+=pairSum[i];
            maxSum+=pairSum[m-i-1];
        }
            return (maxSum-minSum);
    }
};



//GIVING WRONG ANSWER
//https://youtu.be/1V3OdOZbo1w
//NEWTON SCHOOL
class Solution 
{
public:
    long long putMarbles(vector<int>& weights, int k) 
    {
        int maxScore=weights[0] + weights[weights.size()-1];
        int minScore=weights[0] + weights[weights.size()-1];
        vector <int> b;
        for(int i=1;i<weights.size()-1;i++)
        {
            b.push_back(weights[i]+weights[i-1]);
        }
        sort(b.begin(),b.end());
        int size=b.size(); //b.size() ko min() ke andar ralhne par koi toh bhi error de rha hai
        for(int i=0;i< min(k-1,size);i++)
        {
            minScore += b[i];
        }
        reverse(b.begin(),b.end());
        for(int i=0;i<min(k-1,size);i++) //b.size() ko min() ke andar ralhne par koi toh bhi error de rha hai
        {
            maxScore += b[i];
        }

        return (maxScore-minScore);
    }
};