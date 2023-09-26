//300. Longest Increasing Subsequence

#include<bits/stdc++.h>
using namespace std;

//OBSERVATION:..................................................
//if you sort then also it does not gaurantee that the total length is going to be the ans, that is the longest increasing chain,not just because there can be b and c such that b=c but also because let say there the result after sorting goes like...{1,2},{3,4},{5,13},{8,10},{11,12}, sorting done based on the first element in the pair,then if you include {5,13} in your ans then you won't be able to include {8,10} and {11,12} because that b<c condition is not meeting....but on the other hand if you skip {5,13} then you will be able to add up two more pairs in you ans...
//CONCLUSION: sorting alone doesn't give you answer,you still need to apply take  and not take approach.


//====================================================
//CODESTORYWITHMIK

//You can select pairs in any order.   (MENTIONED IN QUESTION)  //that's why we are free to sort.
//https://youtu.be/DlgGx8GRo9M?list=PLpIkg8OmuX-JhFpkhgrAwZRtukO0SkwAt

//by default sorting will be on the basis of first element in the pair but if we want on the basis of second element in the pair,we need to provide a custom comparator function or lambda expression.
/*
    sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) 
    {
        return a.second < b.second;
    });
*/




//================================================================
//codestorywithMIK
//TC:O(N^2)
class Solution 
{
public:
    int n;
    int t[1001][1001];

    int solve(int i,int p,vector<vector<int>>& pairs)
    {
        //base case
        if(i>=n) return 0;
        if(p!=-1 && t[i][p]!=-1) return t[i][p];

        //take
       int take=0; //take ban hi nhi payega kabhi agar if condition kabhi true nhi hui toh,isliye yahan par banana zaroori hai,varna compile time error dega.
        if(p==-1 || pairs[p][1]<pairs[i][0])
        {
            take=1+solve(i+1,i,pairs); //previous will be i and not pairs[i][1].
        }
        //not take
        int not_take=solve(i+1,p,pairs);

        if(p!=-1) t[i][p]=max(take,not_take);
        return max(take,not_take);
    }
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        sort(pairs.begin(),pairs.end()); //by default first element ke according sort ho jayega.
        ///by default sorting will be on the basis of first element in the pair but if we want on the basis of second element in the pair,we need to provide a custom comparator function or lambda expression.
        n=pairs.size();
        memset(t,-1,sizeof(t));
        return solve(0,-1,pairs);
    }
};