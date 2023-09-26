//Leaders in an array

/*

Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader. 
You don't need to read input or print anything. The task is to complete the function leader() which takes array A and n as input parameters and returns an array of leaders in order of their appearance.


*/


//Expected Time Complexity: O(n)
//Expected Auxiliary Space: O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n)
    {
        vector <int> ans;
      
       int max=a[n-1];
       ans.push_back(max);
       
       
       for(int i=n-2;i>=0;i--)
       {
           if(a[i]>=max)
           {
               max=a[i];
               ans.push_back(max);
           }
       }
       //better option
       reverse(ans.begin(),ans.end());
    //    vector <int> f_ans;
    //    for(int i=ans.size()-1;i>=0;i--) f_ans.push_back(ans[i]);
    //    return f_ans;
        return ans;
        
    }
};