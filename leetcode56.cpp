//56. Merge Intervals



//https://youtu.be/IexN60k62jo
//solve 








#include<vector>
#include<iostream>
using namespace std;


//error:
//not understood the question fully(tricky)
//intervals = [[1,4],[0,4]]
//Output: [[1,4]]
//Expected:[[0,4]]



//trial

class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector <int> v;
        int n=intervals.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<intervals[0].size();j++)
            {
                v.push_back(intervals[i][j]);
            }
        }

        for(int i=1,j=2;i<v.size() && j<v.size();)
        {
            if(v[i]>=v[j])
            {
                
                v.erase(v.begin()+j-1);
                v.erase(v.begin()+j-1);
                i=j-1;
            }
            else
            {
                i++;
                j++;
            }
        }
        vector<vector<int>> ans;
        for(int i=0,j=1;i<v.size() && j<v.size();)
        {
            ans.push_back({v[i],v[j]});
            i=j+1;
            j=i+1;
        }

        return ans;
    }
};


//****************CORRECTED TRIAL***************************
//WRONG ANS 
//[[1,4],[2,3]] , output:[[1,3]]   , expected:[[1,4]]

#include<algorithm>

class Solution 
{
public:
        
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector <int> v;
        int n=intervals.size();
    //ek function ki definition ke andar doosre function ki definition nhi likh sakte. (CONCEPT)

    //sorting the interval on the basis on first element using lambda function.
        sort(intervals.begin(),intervals.end(),[](const vector <int>& a,const vector <int>& b)
        {
            return a[0]<b[0];
        });
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<intervals[0].size();j++)
            {
                v.push_back(intervals[i][j]);
            }
        }

        for(int i=1,j=2;i<v.size() && j<v.size();)
        {
            if(v[i]>=v[j])
            {
                
                v.erase(v.begin()+j-1);
                v.erase(v.begin()+j-1);
                i=j-1;
            }
            else
            {
                i++;
                j++;
            }
        }
        vector<vector<int>> ans;
        for(int i=0,j=1;i<v.size() && j<v.size();)
        {
            ans.push_back({v[i],v[j]});
            i=j+1;
            j=i+1;
        }

        return ans;
    }
};