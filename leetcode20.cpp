//20. Valid Parentheses

//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(n) //because we are using stack data structure

//https://youtu.be/wkDfsKijrZ8


//genie ashwani --> for concept (youtube)
//https://youtu.be/yrNYxHaXvtM

#include<iostream>
#include<stack>
#include<string>
using namespace std;


class Solution {
public:
    bool isValid(string s) 
    {
        stack <int> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='{' || s[i]=='(' || s[i]=='[' )
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty()) return false; //very important for handling corner cases.
                
                char c=st.top();
                st.pop(); //pop() returns nothing in c++,it only deletes the top most element in the stack at any point of time. Whereas in java it returns the top most element and deletes it from the stack.
                if((c=='{' && s[i]=='}') ||(c=='(' && s[i]==')')||(c=='[' && s[i]==']'))
                {
                    
                }
                else return false;

            }
        }
        if(st.empty()) return true;
        else return false;
    }
};


//NOT OPTIMAL (BUT FOLLOW UP) NOT USING STACK DATA STRUCTURE SO NO EXTRA SPACE

//TIME COMPLEXITY:O(n^2)
//SPACE COMPLEXITY:O(1)

//https://youtu.be/aoYm3bmOPHw


