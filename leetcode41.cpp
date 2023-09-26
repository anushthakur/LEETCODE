//41. First Missing Positive


//CONCEPT:
//[] operator can be used with map not set //https://www.geeksforgeeks.org/inserting-elements-in-stdmap-insert-emplace-and-operator/







//TRIAL 1 WITH WORST TIME COMPLEXITY AND WORST SPACE COMPLEXITY


//MY THIS TRIAL SOLUTION BECOMES CORRECT ANSWER FOR A SLIGHT VARIANT/DEVIATION OF THE SAME QUESTION...

//if we needed to find smallest missing number in the numbers which are given ,then my answer is absolutely correct.But here in this ques. we need to find smallest positive integer that is missing,that is in test case where nums = [7,8,9,11,12],expected output must be 1 and not 10.

/*
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;


class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        vector<int> :: iterator it;
        set<int> st;
        it=min_element(nums.begin(),nums.end());

        while(*it<=0)
        {
            nums.erase(it);
            it=min_element(nums.begin(),nums.end());
        }
        //st[*it]++; //wrong  [] operator can be used with map not set //https://www.geeksforgeeks.org/inserting-elements-in-stdmap-insert-emplace-and-operator/
        st.insert(*it); //log n
        nums.erase(it);
        it=nums.begin();
        while(it!=nums.end())
        {
            if(*it!=*(st.crbegin())+1  && *it>*(st.crbegin()))
            {
                return *(st.crbegin())+1;
            }
            else
            {
               st.insert(*it);
            }
            it++;
        }
    return *(st.crbegin())+1;
    }
};
*/




//TRIAL 2
//TIME COMPLEXITY:O(n^2)
//SPACE COMPLEXITY:O(1)

#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
       int ans=1; //because 1 is the smallest possible positive integer
       for(int i=0;i<nums.size();i++)
       {
           if(find(nums.begin(),nums.end(),ans)!=nums.end())
           {
               ans++;
           }
           else return ans;
       } 
       return ans;
    }
};


//trial 3
//TIME COMPLEXITY:O(N log N)
//SPACE COMPLEXITY:O(1)

class Solution 
{
 public:

//  int partition(vector<int>& nums,int l,int r)
//  {
//      int pivot=nums[l];
//      int i=l+1,j=r,temp;
//      while(i<j)
//      {
//          while(nums[i]<=pivot) i++;
//          while(nums[j]>pivot) j--;
//          if(i<j)
//          {
//             temp=nums[i];
//             nums[i]=nums[j];
//             nums[j]=temp;
//          }
//      }
//      temp=nums[l];
//      nums[l]=nums[j];
//      nums[j]=temp;
//      return j;
     
//  }

//  void quicksort(int l,int r,vector <int> & nums)
//  {
//      int partitionindex;
//      if(l<r)
//      {
//          partitionindex=partition(nums,l,r);
//          quicksort(l,partitionindex,nums);
//          quicksort(partitionindex+1,r,nums);
//      }
//  }

    int firstMissingPositive(vector<int>& nums) 
    {
        //quicksort(0,nums.size()-1,nums);
        sort(nums.begin(),nums.end()); //O(N log N)
        int ans=1; int prev;
        for(int i=0;i<nums.size();i++) //O(N)
        {
            if(nums[i]!=ans && nums[i]>0 && nums[i]!=prev)
            {
                return ans;

            }
            else if(nums[i]==ans && nums[i]>0) 
            {
                prev=ans;
                ans++;
            }
        }
        return ans;
    }
};


//APPROACH 1
//TIME COMPLEXITY:O(N log N)
//SPACE COMPLEXITY:O(N)
#include<set>

class Solution 
{
  public:
    int firstMissingPositive(vector<int>& nums) 
    {
        set <int> st;
        for(int key:nums)//O(N)
        {
            st.insert(key);//O(log N)
        }
        int ans=1;
        while(st.find(ans)!=st.end()) //O(log N) for set.find(element) and it will happen N times in worst case
        //O(N log N)
        {
            ans++;
        }
        return ans;

    }
};

//APPROACH 2
//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(n)
#include<unordered_set>
class Solution 
{
  public:
    int firstMissingPositive(vector<int>& nums) 
    {
        unordered_set <int> st;

        for(int i=0;i<nums.size();i++) //O(n)
        st.insert(nums[i]);//O(1)

        int ans=1;
        for(int i=1;i<=nums.size();i++) //O(n)
        {
            if(st.find(ans)!=st.end()) //O(1) //visit scaler.com
            {
                ans++;
            }
            else return ans;
        }
        return ans;


        
    }
};


//Approach 3 BEST SOLUTION 
//YOUTUBE:https://youtu.be/L1u-R_s2Mok

//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(1)

//after knowing that 1 is present,replace all elements in the array which are <=0 and >n by 1.


#include<cmath>
class Solution 
{
  public:
    int firstMissingPositive(vector<int>& nums) 
    {
        bool containsOne=false;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                containsOne=true;
                break;
            }
        }
        if(!containsOne) return 1;
        int n=nums.size();
        if(n==1) return 2;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=0 || nums[i]>n)
            {
                nums[i]=1;
            }
        }

        for(int i=0;i<nums.size();i++)
        {
            int x=abs(nums[i]);
            if(nums[x-1]>0)
            {
                nums[x-1]*=-1;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                return i+1;               
            }
        }
        return n+1;
    }
};

