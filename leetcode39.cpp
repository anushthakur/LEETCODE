//39. Combination Sum

//TAKE U FORWARD

//Whenever there's a problem of printing combinations or subsequences,what must strike is recursion

//assuming the average length of every combination generated is k,because we are storing the valid combination into another data structure,which is not a constant operation.Adding a data structure into another data structure takes linear time complexity and not constant time.

//TIME COMPLEXITY: when an element is only chosen once,is 2^n * k 
//But here an element can be chosen unlimited number of times.(The same number may be chosen from candidates an unlimited number of times) So,TIME COMPLEXITY: 2^t * k
//(will take a time complexity of k for every recursion call in its base case to put into the data structure)
//SPACE COMPLEXITY: variable,completely depends upon the number of combinations possible,unpredictable.
//Assuming there are x combinations possible,and assuming k to be the average length,SPACE COMPLEXITY: x * k.(hypothetical)



//Ques) return a list of all unique combinations ,can return combinations in any order,Given an array of distinct integers,The same number may be chosen from candidates an unlimited number of times.
#include<iostream>
#include<vector>
using namespace std;
//elements(integers) are distinct,so unordered_set is not required.

class Solution
{
    public:
   
   void func(vector<int>& vect,int index,int target,vector<int>& empds,vector<vector<int>> &ans)
    {
        //base condition
        if(index>=vect.size())
        {
            if(target==0)
            {
                ans.push_back(empds);
            }
            return;
        }
        //pick
        if(target>=vect[index])
        {
            empds.push_back(vect[index]);
            func(vect,index,target-vect[index],empds,ans);
            empds.pop_back();
        }
        // don't pick
        func(vect,index+1,target,empds,ans);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector <int> empds;
        func(candidates,0,target,empds,ans);
        return ans;
    }
    
    
    
};


int main()
{
    vector <int> vect{2,3,6,7};
    int target=7;
    
    Solution obj;
    vector<vector<int>> ans;
    ans=obj.combinationSum(vect,target);
    cout<<"The unique combinations are: "<<endl;
   // Displaying the 2D vector
   //refer--> https://www.geeksforgeeks.org/vector-of-vectors-in-c-stl-with-examples/
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
        {
             cout << ans[i][j] << " ";
        }
           
        cout << endl; 
    }
    
    return 0;
}