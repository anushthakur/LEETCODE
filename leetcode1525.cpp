//1525. Number of Good Ways to Split a String


#include<iostream>
#include<unordered_map>
using namespace std;
/*
class Solution 
{
public:
//trial TLE
    int numSplits(string s) 
    {
        int count=0;
        if(s.length()==1) return 0;
        else if(s.length()==2) return 1;
        int i=0;
        int j=i+1;
        unordered_map<char,int> mp2;
        for(int i=0;i<s.length();i++)
        {
            mp2[s[i]]++;
        }
        
        while(j<s.length())
        {   
            unordered_map <char,int> mp1;
            i=0;
            while(i<j)
            {
                mp1[s[i]]+=1;
                mp2[s[i]]-=1;
                if(mp2[s[i]]<=0) mp2.erase(s[i]);
                i++;
            }
            if(mp1.size()==mp2.size()) count++;
            mp2.erase(mp2.begin(),mp2.end());
            for(int i=0;i<s.length();i++)
            {
                mp2[s[i]]++;
            }
            
            j++;
        }
        return count;
    }
};

*/






//chatgpt corrected trial TLE

class Solution 
{
public:
//============================================================
    //TRIAL 2
/*

Reinitializing mp2 in each iteration would result in unnecessary work because you are only moving one character from mp2 to mp1 and decrementing its count. Instead of clearing and rebuilding mp2, you can simply update mp2 incrementally by decrementing the count for the character that you moved to mp1.

*/

    int numSplits(string s) 
    {
        int count = 0;
        int n = s.length();

        unordered_map<char, int> mp1;  // Map for the first substring
        unordered_map<char, int> mp2;  // Map for the second substring

        // Initialize mp1 and mp2 for the first and second substrings

        /*
            The second for loop iterates through the string from the beginning to the second-to-last character (i < n - 1) because the goal of this loop is to split the string into two non-empty substrings. To achieve this, you want to ensure that there is at least one character in both the left and right substrings. If you iterated through the entire string (including the last character), you would end up with an empty right substring, which is not a valid split.
        */
        for (int i = 0; i < n; i++) 
        {
            mp2[s[i]]++;
        }

        for (int i = 0; i < n - 1; i++) 
        {
            mp1[s[i]]++;
            mp2[s[i]]--;

            if (mp2[s[i]] == 0) 
            {
                mp2.erase(s[i]);
            }

            if (mp1.size() == mp2.size()) 
            {
                count++;
            }
        }

        return count;
    }
};

