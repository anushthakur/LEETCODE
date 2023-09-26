//3. Longest Substring Without Repeating Characters

#include<iostream>
#include<vector>
using namespace std;

//https://youtu.be/qtVh-XEpsJo
class Solution 
{
public:
//TIME COMPLEXITY:O(N)
//SPACE COMPLEXITY:O(256) //CONSTANT
    int lengthOfLongestSubstring(string s) 
    {
        //TAKEUFORWARD

        vector<int>mpp(256,-1); //array working as hash map //because a string can have 256 different characters.

        //left and right pointers
        int left=0;
        int right=0;

        int n=s.length(); //size of the string

        int length=0; //which will store maximum length possible according to the constraints

        while(right<n)
        {
            if(mpp[s[right]]!=-1)
            {
                left=max(left,mpp[s[right]]+1);
            }
            mpp[s[right]]=right;
            length=max(length,(right-left+1));
            right++;
        }

        return length;

        
    }
};