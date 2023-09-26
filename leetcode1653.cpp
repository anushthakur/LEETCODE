//1653. Minimum Deletions to Make String Balanced

#include<iostream>
#include<string.h>
using namespace std;

class Solution 
{
public:
//a must not be after b (interpretation of ques.)

//https://youtu.be/Aga-im0K5MY
//Java coding insight interview preparation

//TIME COMPLEXITY:O(N)
//SPACE COMPLEXITY:O(1)
    int minimumDeletions(string s) 
    {
        int b=0;
        int count=0;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='b') b++;

            if(b>0 && s[i]=='a')
            {
                b--;
                count++;
            }
        }
            return count;
    }
};