//1647. Minimum Deletions to Make Character Frequencies Unique
#include<bits/stdc++.h>
using namespace std;
//codestorywithMIK
class Solution 
{
public:
    int minDeletions(string s) 
    {
        int array[26]={0}; //O(26) --> O(1)
        for(char &x:s)
        {
            array[x-'a']+=1;
        }
        int result=0;
        unordered_set <int> st; //O(N)
        for(int i=0;i<26;i++)
        {
            while(array[i]>0 && st.find(array[i])!=st.end())
            {
                array[i]-=1;
                result++;
            }
            st.insert(array[i]);
        }
        return result;
    }
};