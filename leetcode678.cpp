//678.Valid Parenthesis String

//https://youtu.be/2H9gMIIGyvY

/*********************************WRONG**********************************************************/
//because Left parenthesis '(' must go before the corresponding right parenthesis ')' and this order is not being checked,only count is being checked of both types of parenthesis.
#include<iostream>
#include<string>
using namespace std;
class Solution 
{
 public:
    bool checkValidString(string s) 
    {
        int cl=0,cr=0,cs=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') cl++;
            if(s[i]==')') cr++;
            if(s[i]=='*') cs++;

        }
        if(cl==cr) return true;
        else if((cl+cs)==cr) return true;
        else if((cr+cs)==cl)return true;
        else return false;
    }
};

//**************************WRONG***************************************************************
//because Left parenthesis '(' must go before the corresponding right parenthesis ')' and this order is not being checked,only count is being checked of both types of parenthesis.
class Solution 
{
 public:
    bool checkValidString(string s) 
    {
        if(s.size()==0) return true;
        int cl=0,cr=0,cs=0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') cl++;
            if(s[i]==')') cr++;
            if(s[i]=='*') cs++;

        }
        if(cl==cr) return true;
        //else if((cr+cs)==cl)return true;
        //else if((cl+cs)==cr) return true;
        else if(cl<cr)
        {
            if((cl+cs)>=cr) return true;
            else return false;
        }
        else if(cr<cl)
        {
            if((cr+cs)>=cl) return true;
            else return false;
        }
        return false;
        
    }
};

//****************************************************************************************

//CORRECT SOLUTION
//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(1)

/*
//CONCEPT:
Proceed thinking that I need to ensure 2 things: 
1. For every (, there is a ) or * to right., and
2. For every ), there is a ( or * to left of it.
These are the 2 requirements.
2nd condition you achieve by traversing from left to right. Here you are just ensuring for every ) there is either ( or *. So, at any point of time count of ) is more than count of ( + count of *, mismatch.
Similarly for 1st condition you do right to left scan.

*/


/*
Order is being checked. That's why we are ensuring that during left to right pass, at any point of time count of ')' is <= count of '(' + count of '*', and during right to left pass: at any point of time count of '(' <= count of ')' + count of '*'.
Otherwise we would have simply counted '(' and ')' and '*'.
We are allowed to have more '(' in left to right pass, until we reach to end of string, because corresponding ')' will come after '('. 
Similarly, in right to left pass we are allowed to have more ')' until we reach beginning, because corresponding '(' will come before ')'.
*/


class Solution 
{
 public:
    bool checkValidString(string s) 
    {
        if(s.size()==0) return true;
        int balance=0;

        for(int i=0;i<s.size();i++)
        {
           if(s[i]==')') balance--;
           else balance++;
           if(balance<0) return false;

        }
        if(balance==0) return true;

        balance=0;

        for(int i=s.size()-1;i>=0;i--)
        {
           if(s[i]=='(') balance--;
           else balance++;
           if(balance<0) return false;

        }
        return true;
       
        
    }
};