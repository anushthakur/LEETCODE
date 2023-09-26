//119. Pascal's Triangle II

//https://youtu.be/bR7mQgwQ_o8
//TAKEUFORWARD

#include<bits/stdc++.h>
using namespace std;
class Solution 
{
 public:
    vector<int> generateRow(int row)
    {
        long long ans=1;
        vector<int> temp;
        temp.push_back(1);
        for(int i=1;i<row;i++)
        {
            ans*=row-i;
            ans/=i;
            temp.push_back(ans);
        }
        return temp;
    }

    vector<int> getRow(int rowIndex) 
    {
        return generateRow(rowIndex+1);
    }
};


//Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
class Solution 
{
 public:
    vector<int> generateRow(int row)
    {
        long long ans=1;
        vector<int> temp(row,0);
        temp[0]=1;
        for(int i=1;i<row;i++)
        {
            ans*=row-i;
            ans/=i;
            temp[i]=ans;
        }
        return temp;
    }

    vector<int> getRow(int rowIndex) 
    {
        return generateRow(rowIndex+1);
    }
};