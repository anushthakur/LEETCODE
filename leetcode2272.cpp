//2272. Substring With Largest Variance

#include<iostream>
#include<vector>
#include<unordered_map>
#include <utility>
#include<algorithm>
using namespace std;



//**********************************TRIAL 2 **********************************************
//error:"ab" ,output:1 expected:0
class Solution 
{
public:
    
    static int cmp(pair<char,int>& a,pair<char,int>&b)
    {
        return a.second<b.second;
    }
    int largestVariance(string s) 
    {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        if(mp.size()!=2)
        {
            vector<pair<char,int>> v(mp.begin(),mp.end());
            sort(v.begin(),v.end(),cmp);
             return (v[v.size()-1].second  - v[0].second);
        }
        else
        {
            int countF=0;
            int countS=0;
            int result=-1;

            unordered_map<char,int> :: iterator it;
            it=mp.begin();
            char fst=it->first;
            it++;
            char sec=it->first;

            for(int i=0;i<s.length();i++)
            {
                if(s[i]==fst)
                {
                    countF++;
                }
                else if(s[i]==sec)
                {
                    countS++;
                }
                result=max(result,abs(countF-countS));
            }

             countF=0;
             countS=0;

            for(int i=s.length()-1;i>=0;i--)
            {
                if(s[i]==fst)
                {
                    countF++;
                }
                else if(s[i]==sec)
                {
                    countS++;
                }
                result=max(result,abs(countF-countS));
            }
            return result;
        }
        
    }
};



//TRIAL 3   

class Solution 
{
public:
    
    static int cmp(pair<char,int>& a,pair<char,int>&b)
    {
        return a.second<b.second;
    }
    int largestVariance(string s) 
    {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        
        if(mp.size()==2 && s.length()>2)
        {
            int countF=0;
            int countS=0;
            int result=-1;

            unordered_map<char,int> :: iterator it;
            it=mp.begin();
            char fst=it->first;
            it++;
            char sec=it->first;

            for(int i=0;i<s.length();i++)
            {
                if(s[i]==fst)
                {
                    countF++;
                }
                else if(s[i]==sec)
                {
                    countS++;
                }
                result=max(result,abs(countF-countS));
            }

             countF=0;
             countS=0;

            for(int i=s.length()-1;i>=0;i--)
            {
                if(s[i]==fst)
                {
                    countF++;
                }
                else if(s[i]==sec)
                {
                    countS++;
                }
                result=max(result,abs(countF-countS));
            }
            return result;
        }

        else
        {
            vector<pair<char,int>> v(mp.begin(),mp.end());
            sort(v.begin(),v.end(),cmp);
             return (v[v.size()-1].second  - v[0].second);
        }
        
    }
};


//trial 4

//wrong answer for symmetric string
//"aabbbbaa",output=2,expected=3
class Solution 
{
public:
    
    static int cmp(pair<char,int>& a,pair<char,int>&b)
    {
        return a.second<b.second;
    }
    int largestVariance(string s) 
    {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        
        if(mp.size()==2 && s.length()>2)
        {
            int countF=0;
            int countS=0;
            int result=-1;

            unordered_map<char,int> :: iterator it;
            it=mp.begin();
            char fst=it->first;
            it++;
            char sec=it->first;

            for(int i=0;i<s.length();i++)
            {
                if(s[i]==fst)
                {
                    countF++;
                }
                else if(s[i]==sec)
                {
                    countS++;
                }
                if(countF!=0 && countS!=0)
                result=max(result,abs(countF-countS));
            }

             countF=0;
             countS=0;

            for(int i=s.length()-1;i>=0;i--)
            {
                if(s[i]==fst)
                {
                    countF++;
                }
                else if(s[i]==sec)
                {
                    countS++;
                }
                if(countF!=0 && countS!=0)
                result=max(result,abs(countF-countS));
            }
            return result;
        }

        else
        {
            vector<pair<char,int>> v(mp.begin(),mp.end());
            sort(v.begin(),v.end(),cmp);
             return (v[v.size()-1].second  - v[0].second);
        }
        
    }
};






//**********************************TRIAL 1 ******************************************
//MISSED trick of the question
//error: "aababbb",output:1,expected:3
//not understood the question correctly
class Solution 
{
public:

    static int cmp(pair<int,int>& a,pair<int,int>&b) //https://youtu.be/viOV5NMbLxE
    {
        return a.second<b.second;
    }
    int largestVariance(string s) 
    {
        unordered_map<int,int> mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        vector<pair<int,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),cmp); //LOGICTOCODE (youtube channel)
        
//The error message you encountered indicates that there is an issue with the usage of the sort function in your code. Specifically, it seems that you are attempting to pass a non-static member function cmp as the comparison function for sorting.

//The sort function expects either a function pointer or a callable object as the comparison function. However, non-static member functions have an implicit this parameter, which makes it incompatible with the expected function signature.

//To resolve this error, you can use a static member function or a lambda function as the comparison function. Here's an example using a lambda function
        
        return (v[v.size()-1].second  - v[0].second);
    }
};
