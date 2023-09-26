//744. Find Smallest Letter Greater Than Target


#include<bits/stdc++.h>
using namespace std;
//brute force
//TIME COMPLEXITY:O(n)
class Solution 
{
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        for(int i=0;i<letters.size();i++)
        {
            if(letters[i]>target) return letters[i];
        }
        return letters[0];
    }
};

//BINARY SEARCH
//TIME COMPLEXITY:O(log n)
class Solution 
{
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
            int l=0;
            int r=letters.size()-1;
            int position=-1;
            int mid;
            while(l<=r)
            {
                mid=l+((r-l)/2);
                if(letters[mid]>target)
                {
                    position=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }

            if(position==-1) return letters[0];
            else return letters[position];
    }
};

//STL
//TIME COMPLEXITY:O(log n)
class Solution 
{
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {           
    //upper_bound gives iterator... To convert iterator to index we have to subtract the iterator of 0th idx i.e., letters.begin()
                int idx=upper_bound(letters.begin(),letters.end(),target)-letters.begin();
                if(idx==letters.size()) return letters[0];
                else return letters[idx];
    }
};