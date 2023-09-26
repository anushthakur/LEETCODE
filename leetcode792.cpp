//792. Number of Matching Subsequences

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//upper_bound() is a function that operates on sorted containers like vectors, arrays, or other sequences. It returns an iterator pointing to the first element in the range that is greater than the specified value.
//codewithAlisha
class Solution 
{
public:
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        unordered_map <char,vector<int>> mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]].push_back(i);
        }
        int count=0;
        for(int i=0;i<words.size();i++)
        {
            string x=words[i];
            int lastindex=-1;
            int j;
            for(j=0;j<x.length();j++)
            {
                vector<int> :: iterator it;
                it=upper_bound(mp[x[j]].begin(),mp[x[j]].end(),lastindex);


                if(it==mp[x[j]].end())
                {
                    break;
                }
                lastindex=*it;


            }
            if(j==x.length()) count++; //ek poora subsequence mil gya saari conditions satisfy karne vala


        }
        return count;
    }
};


/*
class Solution 
{
public:
    //TRIAL 2 //wrong 43/53 figure out???
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        unordered_map <char,int> mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        int count=0;
        for(int i=0;i<words.size();i++)
        {
            unordered_map <char,int> m;
            for(int j=0;j<words[i].size();j++)
            {
                m[words[i][j]]++;
            }
            bool flag=true;
            for(const auto & x:m)
            {
                if(x.second>mp[x.first]) 
                {
                    flag=false;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};
*/





/*

class Solution 
{
public:
    //trial TLE
    bool isValid(string word,string & s)
    {
        int n=word.length();
        int x=0;
        int lastindex=-1;
        for(int j=0;j<n;j++)
        {
                for(int i=0;i<s.length();i++)
                {
                    if(word[j]==s[i] && i>lastindex)
                    {
                        lastindex=i;
                        x++;
                        break;
                    }
                }
        }
        if(x==n) return true;
        else return false;
       
    }

    int numMatchingSubseq(string s, vector<string>& words) 
    {
        int count=0;
        for(int i=0;i<words.size();i++)
        {
            
                if(isValid(words[i],s)) count++;
            
        }
        return count;
    }
};
*/