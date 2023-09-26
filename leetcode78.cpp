//78.Subsets

//Ques)  array of unique elements,return all possible subsets (the power set).The solution set must not contain duplicate subsets. Return the solution in any order.


//ITERATIVE APPROACH

//ITERATIVE APPROACH (prakash shukla)
class Solution 
{
public:

/*
//****************CONCEPT************************
vector<int> v = {}; 
cout << v.size();  //0
vector<vector<int>> ans;
ans.push_back(v); //{{}} //ans (which is vector of vectors of int) has one empty vector at its index 0 as its element ,so ans.size() is 1 and not 0.
cout << ans.size(); //1
v = ans.at(0); //v={}; //but that means v is empty and its size is 0
v.push_back(1); //v={1};  //first element pushed back i.e. an integer 1 in the empty vector v.
ans.push_back(v); //{{},{1}}
for (vector<int> e : ans) 
{
    cout << e << " ";
}


vector<int> v = {};: This creates an empty vector of integers named "v."

cout << v.size();: This line prints the size of the vector "v." Since "v" is empty, its size is 0. So, the output will be "0."

vector<vector<int>> ans;: This declares a vector of vectors of integers named "ans." At this point, "ans" is empty.

ans.push_back(v);: This pushes the vector "v" (which is empty) into the "ans" vector. So, "ans" now contains one element, which is an empty vector of integers.

cout << ans.size();: This line prints the size of the "ans" vector. Since "ans" contains one element (an empty vector), the output will be "1."

v = ans.at(0);: This line assigns the first element of the "ans" vector (which is the previously added empty vector) to the vector "v." Now, "v" also becomes an empty vector.

v.push_back(1);: This line adds an integer element with the value 1 to the vector "v." Now, "v" contains one element, which is the integer 1.

ans.push_back(v);: This line pushes the modified "v" vector (which contains the integer 1) into the "ans" vector. Now, "ans" contains two elements: the first one is an empty vector, and the second one is a vector containing the integer 1.

for (vector<int> e : ans) { cout << e << " "; }: This loop iterates through the "ans" vector and prints each element.



*/

//ITERATIVE APPROACH

//https://youtu.be/kYY9DotIKlo?list=PLzffTJx5aHaSJ4XaG55cI3Z0VrNOyLWpH

//TIME COMPLEXITY:O(N*2^N) //N=SIZE OF ARRAY,n=size of ans i.e. saare subsets(2^N)
//SPACE COMPLEXITY:O(N*2^N)  //size of ans i.e. saare subsets(2^N) into N(ek element ki maximum sixe ho sakti hai); basically m*n
    vector<vector<int>> subsets(vector<int>& nums) 
    {
         vector<vector<int>> ans;
         //vector<int> v={}; //or 
         vector<int>v;
         ans.push_back(v);

         for(int e:nums)              //e=//1             //2                         //3 
         {
             int n=ans.size();      //n=//1             //2                         //4
             for(int i=0;i<n;i++)  //i=//0             //0,1                       //0,1,2,3
             {
                 v=ans.at(i);        //{}            //{};{1}                    //{};{1};{2};{1,2}
                 v.push_back(e);    //{1}           //{2};{1,2}                 //{3};{1,3};{2,3};{1,2,3}
                 ans.push_back(v); //{{},{1}}      //{{},{1},{2}};{{},{1},{2},{1,2}}                         //{{},{1},{2},{1,2},{3}} ; {{},{1},{2},{1,2},{3},{1,3}};{{},{1},{2},{1,2},{3},{1,3},{2,3}} ; {{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3}}
                 
                 
             }
         }
         return ans;
    }
};

//RECURSIVE APPROACH(BACKTRACK)
#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
  public:

    void func(int index,vector<int>& nums,vector<int>& ds,vector<vector<int>> & ans)
    {   
        if(index>=nums.size())
        {
            ans.push_back(ds);
            return;
        }

        //take
        ds.push_back(nums[index]);
        func(index+1,nums,ds,ans);
        ds.pop_back();

        //not take
        func(index+1,nums,ds,ans);


    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> ds;
        func(0,nums,ds,ans);
         return ans;
    }
};

int main()
{
    vector <int> vect {1,2,3};
    vector<vector<int>> ans;
    Solution obj;
    ans=obj.subsets(vect);

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