
//Minimum indexed character

#include<bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        unordered_set <char> us;
        for(const auto & c:patt)
        {
            us.insert(c);
        }
        for(int i=0;i<str.size();i++)
        {
            if(us.find(str[i])!=us.end()) return i;
        }
        return -1;
    }
};