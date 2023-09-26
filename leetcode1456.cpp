//1456. Maximum Number of Vowels in a Substring of Given Length


//https://youtu.be/jhW7VwP2Djw

//https://quanticdev.com/algorithms/dynamic-programming/kadanes-algorithm/


#include<bits/stdc++.h>
using namespace std;
//sliding window technique used (TRIAL)
//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(1)
class Solution 
{
 public:
    int maxVowels(string s, int k) 
    {
        int maxcount=0;
        int wincount=0;

        for(int i=0;i<k;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
                wincount++;
            }
        }
        maxcount=max(wincount,maxcount); //O(1) //#include <algorithm>

        for(int i=k;i<s.size();i++)
        {
            if(s[i-k]=='a' || s[i-k]=='e' || s[i-k]=='i' || s[i-k]=='o' || s[i-k]=='u')
            {
                wincount-=1;
            }
             if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
                wincount++;
            }
            maxcount=max(wincount,maxcount); //O(1)
        }
        return maxcount;
    }
};


//BETTER WAY OF WRITING THE SAME CODE

class Solution {
public:
    int maxVowels(string s, int k) 
    {
        int temp=0;
        for(int i=0; i<k; i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' )
                temp++;
        }
        int tx=temp;
        cout<<s.length();
        if(k==s.length())
            return temp;
        
        for(int i=k; i<s.length(); i++)
        {
            if( s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' )
                temp++;
            if( s[i-k]=='a' || s[i-k]=='e' || s[i-k]=='i' || s[i-k]=='o' || 
                s[i-k]=='u' )
                temp--;
            tx=max(tx,temp);
        }
        return tx;
    }
};