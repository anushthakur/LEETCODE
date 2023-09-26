//946.Validate stack sequences

//observations:

//distict elements(avoid confusion ki kaunsa element pop hua,example there are two 4's in pushed array,then it will be difficult to figure out which 4 has been talked about in popped array 1st one or 2nd one).

//initially stack is empty(that means pehla operation push hi hoga).

//popped is a permutation of pushed(pushed aur popped arrays mein same elements honge aisa nhi hoga ki pushed aur popped main koi aisa element hai jo doosre mein nhi hai).

//lengths of pushed and popped are same.


//*************************************************************************
/*
//Time Limit Exceeded
//TRIAL

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution 
{
 public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        stack <int> stk;
        
        int i=0;
        while(i<pushed.size())
        {
            if(pushed[i]!=*(popped.begin()))
            {
                stk.push(pushed[i]);
                i++;
            }
            else
            {
                popped.erase(popped.begin());
                i++;
                if(stk.top()==*(popped.begin()))
                {
                    stk.pop();
                    popped.erase(popped.begin());
                }
                else if(pushed[i]==*(popped.begin()))
                {
                     popped.erase(popped.begin());
                }
            }
        }
        while(!stk.empty())
        {
            if(stk.top()==*(popped.end()))
            {
                stk.pop();
                popped.erase(popped.end());
            }
        }
        return (stk.empty());
    }
};

int main()
{

    Solution obj;
    vector <int> pushed{1,2,3,4,5};
     vector <int> popped {4,5,3,2,1};
    bool ans=obj.validateStackSequences(pushed,popped); 
    cout<<ans;
    return 0;
}

*/

//*************************APPROACH 1**************************************************************

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//GANTAVYA MALVIYA
//BRUTE FORCE (USING STACK)
//TIME COMPLEXITY:O(n) (beacuse worst case mein saare n elements ko traverse kiya)
//SPACE COMPLEXITY:O(n)

//______________________________________________________________________________
/*
//giving segmentation error
class Solution 
{
 public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int j=0;
        stack <int> stk;
        for(auto x:pushed)
        {
            stk.push(x);
            
            while(stk.top()==popped[j]  &&  !stk.empty())
            {
                stk.pop();
               
                j++;
            }
            
        }
        
        return stk.empty();
    }
};

*/
//____________________________________________________________________________________


//**********************************************************


//___________________________________________________________________
/*
//some error
class Solution 
{
 public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int i=0,j=0;
        stack <int> stk;
        while(i<pushed.size())
        {
            stk.push(pushed[i]);
            i++;
            
            while(stk.top()==popped[j]  &&  !stk.empty())  //here error is coming
            //to remove error type (!stk.empty() && stk.top()==popped[j])
            {
                stk.pop();
               
                j++;
            }
            //i++;
            
        }
        
        return stk.empty();
    }
};
*/

//ERROR:
/*
Line 171: Char 16: runtime error: reference binding to misaligned address 0xbebebebebebec0ba for type 'int', which requires 4 byte alignment (stl_deque.h)
0xbebebebebebec0ba: note: pointer points here
<memory cannot be printed>
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/stl_deque.h:180:16
*/
//__________________________________________________________________________




class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i=0,j=0;

        while(i<pushed.size()){
            stk.push(pushed[i]);
            i++;
            while(!stk.empty() && stk.top()==popped[j]){
                stk.pop();
                j++;
            }
            //i++; //fine both ways
        }

        return stk.empty();
    }
};


//***************************************APPROACH 2**********************************************************
//OPTIMIZED APPROACH
//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(1)

//using pushed array itself as a stack
//AYUSHI SHARMA

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        for(auto ele : pushed){
            pushed[i++] = ele; //pushing in the stack
            while(i>0 && pushed[i-1]==popped[j]){
                --i;++j;
            }
        }
        return i==0; //if i becomes equal to zero that means stack got empty
    }
};






int main()
{

    Solution obj;
    vector <int> pushed{1,2,3,4,5};
     vector <int> popped {4,5,3,2,1};
    bool ans=obj.validateStackSequences(pushed,popped); 
    cout<<ans;
    return 0;
}