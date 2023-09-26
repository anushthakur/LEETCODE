//2085. Count Common Words With One Occurrence


//TRIAL
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution 
{
 public:
    int countWords(vector<string>& words1, vector<string>& words2) 
    {
        int count=0;
        unordered_map <string,int> map1;
        unordered_map <string,int> map2;
        unordered_map <string,int> :: iterator it;
       

        for(const string& x:words1)
        {
            map1[x]++;
        }

        for(const string& x:words2)
        {
            map2[x]++;
        }
         for(const auto& x:map1)
        {
            if( map2.find(x.first)!=map2.end() )
            {
                it=map2.find(x.first);
                if(it->second==1 && x.second==1)count++;
                
            }
           
        }
     return count;
      
    }
};