//1431. Kids With the Greatest Number of Candies

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



class Solution 
{
   public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector <bool> ans(candies.size(),false);
        int maxC=*max_element(candies.begin(),candies.end());
        //*max_element() function in c++ is in <algorithm> header file
        //https://www.geeksforgeeks.org/max_element-in-cpp/

        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]+extraCandies>=maxC)
            {
                ans[i]=true;
            }
        }
        return ans;
    }
};



int main()
{   Solution obj;
vector <int> candies{2,3,5,1,3};
int extraCandies = 3;
vector <bool> ans;
 ans=obj.kidsWithCandies(candies,extraCandies);
 for(int i=0;i<ans.size();i++) cout<<boolalpha<<(ans[i])<<" ";
 //The boolalpha() method of stream manipulators in C++ 
    
    return 0;
}