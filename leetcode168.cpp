//168. Excel Sheet Column Title

#include<bits/stdc++.h>
using namespace std;
//codestorywithMIK
class Solution 
{
public:

    string convertToTitle(int columnNumber) 
    {
        string result;
        while(columnNumber>0)
        {
            columnNumber--;
            int rem =columnNumber%26;
            char c = rem+'A';
            result.push_back(c);
            columnNumber=columnNumber/26;
        }
        reverse(result.begin(),result.end());

        return result;
    }
};