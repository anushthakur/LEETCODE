// 318. Maximum Product of Word Lengths

#include<bits/stdc++.h>
using namespace std;
//code with alisha
class Solution
{
public:

    int ans=0;
    int maxProduct(vector<string>& words) 
    {
        vector<int>state(words.size());
        for(int i=0;i<words.size();i++)
        {
            for(const auto& c:words[i])
            {
                state[i] = state[i] | (1<<(c-'a'));
            }
            for(int j=0;j<i;j++)
            {
                if(!(state[i]&state[j]))
                {
                    //no common letter
                    if(words[i].size()*words[j].size()>ans)
                    {
                        ans=words[i].size()*words[j].size();
                    }
                }
            }
        }
        return ans;
    }
};