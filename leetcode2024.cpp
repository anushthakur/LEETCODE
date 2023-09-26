//2024. Maximize the Confusion of an Exam

#include<bits/stdc++.h>
using namespace std;

//CODESTORYWITHMIK
//https://youtu.be/vY06L8hZVGI
//Look other approaches in this video

class Solution 
{
public:
    int maxConsecutiveAnswers(string answerKey, int k) 
    {
        int result=0;
        int i=0;
        int j=0;

        unordered_map <char,int> mp;

        while(j<answerKey.length())
        {
            mp[answerKey[j]]++;

            while(min(mp['T'],mp['F'])>k)
            {
                mp[answerKey[i]]--;
                i++;
            }

            result=max(result,(j-i+1));
            j++;
        }
        return result;
    }
};