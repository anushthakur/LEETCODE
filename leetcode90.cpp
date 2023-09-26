//90.Subsets II

//Ques)Given an integer array that may contain duplicates, return all possible subsets(the power set).
//The solution set must not contain duplicate subsets. Return the solution in any order.
 


 //BUG IN THE SOLUTION (WRONG OUTPUT FOR [4,4,4,1,4])
#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution 
{
  public:

    void func(int index,vector<int>& nums,vector<int>& ds,set<vector<int>> & s)
    {   
        if(index>=nums.size())
        {
            s.insert(ds);
            return;
        }

        //take
        ds.push_back(nums[index]);
        func(index+1,nums,ds,s);
        ds.pop_back();

        //not take
        func(index+1,nums,ds,s);


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        set<vector<int>> s;
        vector<vector<int>> ans;
        vector<int> ds;
        func(0,nums,ds,s);
        ans.assign(s.begin(),s.end());
         return ans;
    }
};

int main()
{
    vector<int> vect {1,2,2};
    vector<vector<int>> ans;
    Solution obj;
    ans=obj.subsetsWithDup(vect);

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}