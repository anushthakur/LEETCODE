
//2215. Find the Difference of Two Arrays

#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;



//OPTIMAL SOLUTION

//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(n)

class Solution 
{
  public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        //unordered_set instead of set because we can return in any order(read the note of question)
        unordered_set<int> set1(nums1.begin(), nums1.end()); //O(n)
        unordered_set<int> set2(nums2.begin(), nums2.end()); //O(n)
        vector<vector<int>> answer(2);

        for (int num : set1) //O(n)
        {
            if (set2.find(num) == set2.end()) //O(1)
            {
                answer[0].push_back(num);
            }
        }

        for (int num : set2) //O(n)
        {
            if (set1.find(num) == set1.end()) //O(1)
            {
                answer[1].push_back(num);
            }
        }

        return answer;
    }
};



//*******************************************************************

//TIME COMPLEXITY:O(n log n)
//SPACE COMPLEXITY:O(n)

class Solution 
{
  public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>> ans(2);

        set<int>arr1;
        
        for(int i=0;i<nums1.size();i++) arr1.insert(nums1[i]); //O(n*log n)
        set<int>::iterator itr1=arr1.begin();

        set<int>arr2;
        
        for(int i=0;i<nums2.size();i++) arr2.insert(nums2[i]); //O(n*log n)
        set<int>::iterator itr2=arr2.begin();

        
        for(itr1;itr1 != arr1.end();itr1++) //O(n)
        {
            if(arr2.find(*itr1)==arr2.end()) //O(log n)
            {
                ans[0].push_back(*itr1);
            }
        }

        for(itr2;itr2 != arr2.end();itr2++) //O(n)
        {
            if(arr1.find(*itr2)==arr1.end()) //O(log n)
            {
                ans[1].push_back(*itr2);
            }
        }
        return ans;
    }
};