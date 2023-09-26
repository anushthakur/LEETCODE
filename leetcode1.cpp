//1. Two Sum
//go through the upsolves and followups of the questions.

//ALL QUESTIONS' SOLUTIONS OF LEETCODE PLATFORM LINK:
//https://walkccc.me/LeetCode/problems/0350/

//*****************************BRUTE FORCE*********************************
//TIME COMPLEXITY : O(n^2)
//SPACE COMPLEXITY: O(1)
/*
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector <int> ans;
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        for(int i=0;i<nums.size()-1;i++)
        {   
            int t=(target-nums[i]);
            for(int j=i+1;j<nums.size();j++)
            {
                //if(nums[j]+nums[i]==target) 
                if(nums[j]==t)
                {
                    ans.push_back(i);
                     ans.push_back(j);
                     return ans;
                }
            }
        }
        return ans;
        
    }
};

int main()
{
    vector <int> vect{3,2,4};
    int target=6;
    Solution obj;
    vect=obj.twoSum(vect,target);
    for(int key:vect)
    {
        cout<<key<<" ";
    }
    

    return 0;
}
*/

//HASH TABLE AND HASH MAP BOTH USE HASHING,BUT ARE DIFFERENT FROM EACH OTHER.
//************************ HASH TABLE******************************

//Implementation of Hash Table : A hash table is traditionally implemented with an array of linked lists. When we want to insert a key/Value pair, we map the key to an index in the array using the hash function. The value is then inserted into the linked list at that position.
//VALUES are not stored in sorted order.

//***********************USING HASH MAP*********************************

//TIME COMPLEXITY: O(n) //ek element ko insert and search karne mein O(1).
//SPACE COMPLEXITY: O(n) //because we are storing every array element in the hash table


//find() --> Returns iterator to the element.
//end()  --> Returns an iterator pointing to the position past the last element in the container in the unordered_map container.
//begin() -->Returns an iterator pointing to the first element in the container in the unordered_map container.

//In C++ MAP ,No two mapped values can have the same key values.
#include<iostream>
#include <algorithm>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector <int> ans;
        unordered_map <int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            if(mpp.find(target-nums[i])!= mpp.end())
            {
                ans.push_back(mpp[target-nums[i]]);
                ans.push_back(i);
                return ans; //we can return as exactly one solution
            }
            else mpp[nums[i]]= i;
        }
        return ans;
    }
};

int main()
{
    vector <int> vect{3,2,4};
    int target=6;
    Solution obj;
    vect=obj.twoSum(vect,target);
    for(int key:vect)
    {
        cout<<key<<" ";
    }
    

    return 0;
}


//**************TWO POINTER TECHNIQUE*************************(YOUTUBE:ASHISH KUMAR)
//NOTE(CONCEPT): IF THE ARRAY IS ALREADY SORTED,IT'S BETTER TO USE TWO POINTER APPROACH,AS THEN IT WOULD ONLY TAKE O(n) TIME COMPLEXITY.

//sort() in STL c++ -->https://www.geeksforgeeks.org/sort-algorithms-the-c-standard-template-library-stl/
class Solution 
{
    //FINAL TIME COMPLEXITY:O(n* log n)
    //SPACE COMPLEXITY:O(log n)
 public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector <int> ans;
        vector<pair<int,int>> v;
       
        //if we sort the array that means position of elements will get disturebed i.e. their indices will also get disturbed.(youtube FRAZ),so we need to pair the element to its index in the original array.
        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],i});
        }
         sort(v.begin(),v.end());  //O(n* log n)

        int i=0,j=nums.size()-1;

        while(i<j) //O(n)
        {
            if(v[i].first + v[j].first==target) 
            {
                ans.push_back(v[i].second);
                ans.push_back(v[j].second);
                return ans;
            }
            else if(v[i].first + v[j].first>target)
            {
                j--;
            }
            else i++;
        }
        return ans;
        
    }
};