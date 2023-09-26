//2390. Removing Stars From a String


/*

//***********************substr() function  in <string.h> in c++ **************************

// C++ program to demonstrate functioning of substr()
#include <iostream>
#include <string.h>
using namespace std;
 
int main()
{
    // Take any string
    string s1 = "Geeks";
 
    // Copy two characters of s1 (starting
    // from position 3)
    string r = s1.substr(3, 2);
 
    // prints the result
    cout << "String is: " << r;
 
    return 0;
}


//OUTPUT: String is: ks
//Time complexity: O(N)
//Auxiliary Space: O(N)

*/




//*********************************  APPROACH 1 *****************************************************




/*
//There is a direct function in the “algorithm” header file for doing reverse that saves our time when programming.

// C++ program to illustrate the
// reversing of a string using
// reverse() function
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "geeksforgeeks";
 
    // Reverse str[begin..end]
    reverse(str.begin(), str.end());
 
    cout << str;
    return 0;
}
//OUTPUT:skeegrofskeeg


//Complexity Analysis:

//Time Complexity: O(N)
//Auxiliary Space: O(1)


*/


//*****************************************
//USING STACK DATA STRUCTURE
//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(n)


#include<iostream>
using namespace std;
#include<stack>
#include<algorithm>
//using stack 
class Solution 
{
 public:
 
  
    string removeStars(string s) 
    {
       stack<char> stk;
         
        int i;
        for( i=0;i<s.length();i++)
        {
            if(s[i]!='*')
            {
                stk.push(s[i]);
            }
            else stk.pop();
        }

         string ans="";
    while(!stk.empty())
    {
       ans.push_back(stk.top());
       stk.pop();
    }
    
    
   
    //reversing string using inbuilt function in <algorithm> header file
    reverse(ans.begin(),ans.end());
    return ans;
    }
};   
















//**************************************** APPROACH 2 *******************************************
//CODE WITH ALISHA 
//TWO POINTER APPROACH(OPTIMAL)
//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(1)

#include<iostream>
#include<vector>

#include<string.h>

using namespace std;



class Solution 
{
 public:
    string removeStars(string s) 
    {
      int i,j;
        for( i=0,j=0;i<s.length() && j<s.length();i++)
        {
           

            if(s[i]!='*')
            {
                
               s[j]=s[i];
                j++;
                
            }
            else 
            {

               j--;
            }
           
        }
       
       
        return s.substr(0,j);
      
    }
};



//********************************APPROACH 3 **************************************

//USING STRING AS STACK AS STRING SUPPORTS PUSH_BACK() AND POP_BACK()
//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(n)

class Solution 
{
 public:
   string removeStars(string s) 
    {
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='*')
            {
                ans.push_back(s[i]);
            }
            else
            {
                ans.pop_back();
            }
        }
        return ans;
    }
};




int main()
{
    string a="leet**cod*e";
    Solution obj;
    string ans=obj.removeStars(a);
    cout<<ans;
    return 0;
}