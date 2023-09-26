//1832. Check if the Sentence Is Pangram


#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
public:
    //trial
    bool checkIfPangram(string sentence) 
    {
       vector<int>v(26,0);
        for(int i=0;i<sentence.length();i++)
        {
            v[sentence[i]-'a']+=1;
        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==0) return false;
        }
        return true;
    }
};