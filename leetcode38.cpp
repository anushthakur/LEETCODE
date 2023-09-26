//38. Count and Say


#include<iostream>
#include<string.h>
using namespace std;


//https://youtu.be/Vp5asrxlg18
//tech adora by nivedita

class Solution 
{
public:
    string countAndSay(int n) 
    {
        string ans="1"; //base case according to constraints given

        for(int x=2;x<=n;x++)
        {
            string previous=ans;
            int size=ans.size();
            ans="";
            int i=0;
            
            while(i<size)
            {
                int j=i;
                while(j<size && previous[j]==previous[i] )
                {
                    j++;
                }

                ans += to_string(j-i) + previous[i];
                 i=j;
            }
           

        }
        return ans;
    }
};