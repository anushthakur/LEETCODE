//1539.Kth Missing Positive Number
#include<iostream>
#include<vector>
using namespace std;

//WORST TIME AND SPACE COMPLEXITIES
//TRIAL : NON-VOID FUNCTION DOES NOT RETURN A VALUE IN ALL CONTROL PATHS
class Solution {
public:
    int check=1;
    int findKthPositive(vector<int>& arr, int k) 
    {
        vector <int> missing;
        for(int i=0;i<arr.size();i++)
        {
            while(arr[i]!=check) 
            {
                missing.push_back(check);
                check++;
            }

            if(arr[i]==check)
            {
                check++;
            }
            
        }
        int diff=k-missing.size();
        if(k<=missing.size())
        {
            return missing[k-1];
        }
        if(diff>0)
        {
            return (check+diff-1);
            
        }
        return 0; //added this,now my solution is accepted
    }
};

//********************************************************************************

//O(N) TIME COMPLEXITY SOLUTION:
//O(1) SPACE COMPLEXITY SOLUTION:
class Solution
{

    public:
     int findKthPositive(vector<int>& arr, int k)
     {
        int prev=1,i=0,ans=0;
        while(k>0 && i<arr.size())
        {
            if(prev!=arr[i])
            {
                k--;
            }
            else
            {
                i++;
            }
            ans=prev;
            prev++;
        }
        ans+=k;
        return ans;
     }
};


//******************************************************************************


//OPTIMAL SOLUTION     //https://youtu.be/kaOb7QofRnU
//O(log N) TIME COMPLEXITY SOLUTION:
//O(1) SPACE COMPLEXITY SOLUTION:

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i;
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid]-mid-1<k){
                low=mid+1;
            }
            else{
                high = mid-1;

            }

        }
        return k+low;
    }
};