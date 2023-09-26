//2864. Maximum Odd Binary Number

#include<iostream>
#include<vector>

using namespace std;
class Solution 
{
public:
//TRIAL
    string maximumOddBinaryNumber(string s) 
    {
        vector<int>v(s.length(),0);
        string ans;
        int count=0;

        //count no. of set bits in the binary representation (brian kernighan algo is not needed here)
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1') count++;
        }

        v[v.size()-1]=1;
        count--;

        for(int i=0;i<v.size()-1;i++)
        {
            if(count>0)
            {
                v[i]=1;
                count--;
            }
            else break;
        }

        for(int i=0;i<v.size();i++)
        {
            ans+=to_string(v[i]);
        }
        return ans;

        
    }
};