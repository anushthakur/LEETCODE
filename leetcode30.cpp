//30. Substring with Concatenation of All Words

//IMP***

#include<vector>
#include<string.h>
#include<iostream>
#include<unordered_map>
using namespace std;

//Madhur Bhaiya
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        int n = words.size();
        int m = words[0].size();
        vector<int> ans;
        if (s.length() < m * n) 
        {
            return ans;
        }
        unordered_map<string, int> wordFreq;
        for (const string& word : words) 
        {
            wordFreq[word]++;
        }
        for (int i = 0; i < m; i++) 
        {
            int left = i;
            int count = 0;
            unordered_map<string, int> currentFreq;    
            for (int j = i; j <= s.length() - m; j += m)
            {
                string word = s.substr(j, m);    
                if (wordFreq.count(word)) 
                {
                    currentFreq[word]++;
                    count++;    
                    while (currentFreq[word] > wordFreq[word]) 
                    {
                        string leftWord = s.substr(left, m);
                        currentFreq[leftWord]--;
                        left += m;
                        count--;
                    }
                    if (count == n) 
                    {
                        ans.push_back(left);
                        currentFreq[s.substr(left, m)]--;
                        left += m;
                        count--;
                    }
                } 
                else 
                {
                    currentFreq.clear();
                    count = 0;
                    left = j + m;
                }
            }
        }
        return ans;
    }
};

/*
//https://youtu.be/yiUV2_PamHY
//Tech adora with nivedita
//TLE

class Solution 
{
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        int n=words.size();
        int m=words[0].size();
        vector <int> ans;
        int t;

        //edge condition
        if(s.length()<m*n)
        {
            return ans;
        }

        for(int i=0;i<=(s.length()-(m*n));i++)
        {
            //for every index i we need a fresh map
            unordered_map <string,int> mp;
            for(const auto& x:words)
            {
                mp[x]++;
            }

            //as all the strings of words matrix must be present,so we are going to check the same number of times as the total number of strings exist, in one go.
            for( t=0;t<n;t++)
            {
                //generating the substring to be checked if present in the map or not
                string str=s.substr(i+t*m,m);

                if(mp.count(str)==0)
                {
                    break; //break from inner for loop and check for next iteration of i.
                }
                else
                {
                   // ======//wrong,figure out why?==========
                   // if(mp[str]>0)
                   // {
                   //     mp[str]--;
                    //}
                    //==================

                    if(mp[str] != 0)
                    {
                        mp[str]--;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            //if all the strings exist in our substring starting from that particular index i,that means it's a valid one and hence that starting index must be included in our answer.
            if(t==n)
            {
                ans.push_back(i);
            }

        }

        return ans;
    }
};
*/






/*
//trial (couldn't solve)
class Solution 
{
public:
    vector <int> ans;
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        int r=words.size();
        int c=words[0].size();
        int lengthOfSubStr=r*c;
        int n=s.length();

        //edge case
        if(lengthOfSubStr>n) return {};

        unordered_map<string,int> mp;
        for(const auto& x:words)
        {
            mp[x]++;
        }

        int start_i=-1; //kyonki hum ko nhi pata substring exist kar bhi rhe hai ki nhi s mein
        int i=0;
        int j=0;

        while(j<n)
        {
            if()
        }

    }
};
*/