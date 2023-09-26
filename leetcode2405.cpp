//2405. Optimal Partition of String

//Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.Return the minimum number of substrings in such a partition.Note that each character should belong to exactly one substring in a partition.

//TRIAL(WRONG,A BUG FOUND)
//"cuieokbs",expected output=1
//not one bud it's incomplete,all wrong for whole bunch of test cases
//because in this code I have only compared extremes if they are same or not,not other members of the string with the new element in order to add that new....so obviously a big blunder happens

//SEARCH FOR A BRUTE FORCE METHOD TOO
/*
class Solution 
{
  public:
    int partitionString(string s) 
    {
        int i=0,j=i+1;
        int partitionCount=0;
        for(i,j;i<s.length() && j<s.length();)
        {
            if(s[i]!=s[j])
            {
                j++;
            }
            else if(s[i]==s[j])
            {
                i=j;
                j=i+1;
                partitionCount++;
            }
        }
        if(i==s.length()-1) partitionCount++;
        return partitionCount;
    }
};



//trial (improved)
class Solution 
{
  public:
    int partitionString(string s) 
    {
        int i=0,j=i+1;
        int partitionCount=0;
        for(i,j;i<s.length() && j<s.length();)
        {
            if(s[i]!=s[j])
            {
                j++;
            }
            else if(s[i]==s[j])
            {
                i=j;
                j=i+1;
                partitionCount++;
            }
        }
        if(i==s.length()-1) partitionCount++;
        if(i==0 && j==s.length()) partitionCount++;
        return partitionCount;
    }
};
*/






//*************************************************************************************
// STL SET

//find(const g):Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to the end.
//end():Returns an iterator to the theoretical element that follows the last element in the set.
//erase(const g):Removes the value ‘g’ from the set.
//clear() :Removes all the elements from the set.

//The time complexities for doing various operations on sets are:
//Insertion of Elements – O(log N)
//Deletion of Elements – O(log N)
//clear()-O(N)   




//YOUTUBE (BRO CODERS)

//TIME COMPLEXITY?

#include<iostream>
#include<string>
#include<set>
using namespace std;
class Solution 
{
  public:
    int partitionString(string s) 
    {
        int count=1;
        set<char> container;
        for(char c:s)
        {
            if(container.find(c)!=container.end())
            {
                count++;
                container.clear();
            }
            container.insert(c);
        }
        return count;
    }
};




