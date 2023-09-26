//7. Reverse Integer

//https://youtu.be/polB7fTyvOo
 //binod suman academy

#include<iostream>
#include<limits.h>
using namespace std;
class Solution 
{
public:
// range of values for a 32-bit signed integer is from -2,147,483,648 to 2,147,483,647. 
    int reverse(int x) 
    {
        int reverse=0;
        
        while(x!=0)
        {
            int digit=x%10;
            x/=10;
            //https://youtu.be/polB7fTyvOo
            //binod suman academy
            if(reverse>INT_MAX/10 || reverse<INT_MIN/10) return 0;

            reverse=(reverse*10) + digit;
        }
        return reverse;
    }
};