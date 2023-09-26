//10. Regular Expression Matching

//first understand the question,how do we go about solving it is next part
//s="aab"
//p="c*a*b"
//my output=false
//expected output=true


#include<bits/stdc++.h>
using namespace std;

//VERY VERY WRONG 
class Solution 
{
 public:
    bool isMatch(string s, string p) 
    {
        int i=0;
        while(i<s.size())
        {
            if(s[i]==p[i] || p[i]=='.') i++;
            if(p[i]=='*')
            {
                if(p[i-1]=='.') i++;
                else 
                {
                    p[i]=p[i-1];
                    if(p[i]==s[i]) i++;
                    else return false;
                }
            }
            if(s[i]!=p[i]) return false;


        }
        return true;
    }
};



//BEST EXPLAINATION ******
//https://youtu.be/HAA8mgxlov8
//NEETCODE (YOUTUBE)

// * --> means, want to use/include previous character or not,and if want to include then how many times(can be any number of times),and if we choose to not include that means the presence of the previous character will be cancelled/ignored.

//DYNAMIC PROGRAMMING(without memoization)

//wrong (bug) //s="mississippi" //p="mis*is*p*." //output=true //expected=false

class Solution 
{
 public:

    bool func(int i,int j,string & s,string & p)
    {
        //BASE CONDITION

        if(i>=s.size() && j>=p.size()) return true;
        if(j>=p.size()) return false;

        bool match=(i<s.size() && (s[i]==p[j] || p[j]=='.'));

        if((j+1 < p.size()) && p[j+1]=='*')
        {
            if(func(i,j+2,s,p) || func(i+1,j,s,p)) return true;
            else return false;
            
        }

        if(match) return func(i+1,j+1,s,p);

        return false;

    }

    bool isMatch(string s, string p) 
    {
        
        return func(0,0,s,p);


    }
};


//chat gpt corrected

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatchHelper(s, p, 0, 0);
    }

private:
    bool isMatchHelper(const string& s, const string& p, int i, int j) {
        // Base condition
        if (i == s.size() && j == p.size()) {
            return true;
        }

        if (j == p.size()) {
            return false;
        }

        bool match = (i < s.size()) && (s[i] == p[j] || p[j] == '.');

        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Skip all consecutive '*' characters
            while (j + 1 < p.size() && p[j + 1] == '*') {
                j += 2;
            }

            if (isMatchHelper(s, p, i, j)) {
                return true;
            }

            while (match && i < s.size()) {
                if (isMatchHelper(s, p, ++i, j)) {
                    return true;
                }
            }

            return false;
        }

        if (match) {
            return isMatchHelper(s, p, i + 1, j + 1);
        }

        return false;
    }
};
