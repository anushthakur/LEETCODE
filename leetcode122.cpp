//122. Best Time to Buy and Sell Stock II

#include<iostream>
#include<vector>
using namespace std;

//CODETHRUST
//GREEDY APPROACH
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int ans=0;
        int buy=prices[0];

        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<buy)
            {
                buy=prices[i];
            }
            else
            {
                ans+=prices[i]-buy;

                while(i<prices.size()-1)
                {
                    if(prices[i]<prices[i+1])
                    {
                        buy=prices[i];
                        break;
                    }
                    else i++;
                }
            }
        }
        return ans;
    }
};