//17. Letter Combinations of a Phone Number
//Lead coding by FRAZ

//CONCEPT
//Whenever we are writing a recursive function,pass array/string/vector/map etc as reference,otherwise there would be created a copy of it everytime when the recursion is called,and a lot of copies will be created which is a waste of memory.

//https://youtu.be/qyHlIdxk820
//time complexity and space complexity concept refer the above link.
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string.h>
using namespace std;
class Solution 
{
  public:
  void fun(int i,string& digits,string& temp,vector<string>& ans,unordered_map<char,string>& mp)
  {
      if(i==digits.size())
      {
          ans.push_back(temp);
          return;
      }
      string str=mp[digits[i]];
      for(int j=0;j<str.size();j++)
      {
          temp.push_back(str[j]);
          fun(i+1,digits,temp,ans,mp);
          temp.pop_back();
      }
  }
    vector<string> letterCombinations(string digits) 
    {
        if(digits.empty())
        {
            return {};
        }


        unordered_map <char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";



        vector<string> ans;
        string temp;
        fun(0,digits,temp,ans,mp);

        return ans;
    }
};


int main()
{
    string digits= "23";
    Solution obj;
    vector<string> ans;
    ans=obj.letterCombinations(digits);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}