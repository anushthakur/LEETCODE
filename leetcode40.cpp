//40.Combination Sum II

//Ques)elements are not distinct,each element can only be used once in the combination.The solution set must not contain duplicate combinations.Return combinations in lexicographic sorted order.

//refer youtube video for STL set -->https://youtu.be/1YpxRmsDuls




#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;


// class Person
// {
//   public:
//   int age;
//   string name;
//   //bool operator < (const Person& rhs) const{ return age>rhs.age;}
//   bool operator < (const Person& rhs) const{ return age<rhs.age;}
 
// };


//************************************************************************************************
//*****************BRUTE FORCE(BASED ON COMBINATION SUM I)****************************************

//TIME COMPLEXITY: 2^n * k * log(m) ,where m is the set size  { putting a data structure of average length k into a set data structure in which insertion,removal and searching have logarithmic complexity}

/*
class Solution 
{
   public:
    void func(vector<int>& vect,int index,int target,vector<int>& empds,set<vector<int>> &ans) //set--> to make sure that duplicate combinations are not stored.
    {
        //base condition
        if(index>=vect.size())
        {
            if(target==0)
            {
                ans.insert(empds);
            }
            return;
        }
        //pick
        if(target>=vect[index])
        {
            empds.push_back(vect[index]);
            func(vect,index+1,target-vect[index],empds,ans);
            empds.pop_back();
        }
        // don't pick
        func(vect,index+1,target,empds,ans);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        set<vector<int>> ans;
        vector <int> empds;

        func(candidates,0,target,empds,ans);  //ek data structure combinations banane ke liye hai(empds) aur ek final valid combinations store karne ke liye(ans)

        vector<vector<int>> res;
        res.assign(ans.begin(), ans.end());
        // refer --> https://www.techiedelight.com/convert-set-vector-cpp/
        
        return res;
    }
    
};

int main()
{
    
    // set<Person> s= {{10,"raj"},{20,"anushka"}};
    // for(Person key:s)
    // {
    //     cout<<key.age<<" "<<key.name<<endl;
    // }
    


    vector <int> vect{2,3,6,7};
    int target=7;
    
    Solution obj;
    vector<vector<int>> ans;
    ans=obj.combinationSum(vect,target);
    cout<<"The unique combination/combinations is/are: "<<endl;
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

*/


//*******************************OPTIMAL APPROACH*******************************************************************
//Instead of trying take or not take for each element,we are going to try to pick subsequences


//Assuming k to be the average length of every combination,assuming x to be number of different combinations
//(assuming that all the elements are unique,so the number of subsequences will be 2^n,where n number of unique elements)TIME COMPLEXITY: 2^n * k
//SPACE COMPLEXITY: k * x




//*****************************OPTIMAL SOLUTION****************************************

class Solution 
{
 public:
    //Hume duplicate combinations data structure ans se hatane na pade,isliye hum subsequence hi aise bana rhe hain jo unique ho(duplicacy subsequence banate samay hi hata rhe hain)
    void func(int index,int target,vector<int> & arr,vector<int> & ds,vector<vector<int>> & ans)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<arr.size();i++) //A loop to choose which index element to be picked as a particular indexed element of our subsequence.

        // Example: int arr[]={1,1,1,2,2}, target=4 //sort the array
        //we can pick 0th/1st/2nd/3rd/4th index element as the first element of our subsequence(these are the 5 possibilities of indices that I can pick up for our first element)
        

        {
            if(i>index && arr[i]==arr[i-1]) continue;  //chaahe 0th/1st/2nd mein se koi bhi index lo for first element,we are ultimately choosing 1 as the first element of the subsequence. So duplicacy of subsequence ko avoid karne ke liye arr[i]==arr[i-1] then continue vala check lagaya,kyonki for example 1st element ki daavedaari ke liye 0th index vala 1 ya 1st index vala 1 ya 2nd index vala 1 lo ek hi baat hai,agar iske liye alag alag subsequence banane lage toh vo subsequences aapas mein duplicates ho jayenge,joki hum avoid karna chaahte hain.

            if(arr[i]>target) break;//yeh hi target se bada hai,toh aage check karne se matlab hi nhi kyonki aage toh array mein aur bade elements milenge kyonki humne array ascending order mein sort kardi hai pehle hi.
            ds.push_back(arr[i]);
            func(i+1,target-arr[i],arr,ds,ans); //each element can be chosen only once,toh isliye i+1,kyonki hum vahi vala index dobara nhi le sakte according to the question.
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {   
        //C++ STL provides a function sort() that sorts a vector or array (items with random access)
        //By default, the sort() function sorts the elements in ascending order.
        //It generally takes two parameters, the first one being the point of the array/vector from where the sorting needs to begin and the second parameter being the length up to which we want the array/vector to get sorted. The third parameter is optional and can be used in cases such as if we want to sort the elements lexicographically.

        //https://www.geeksforgeeks.org/sort-c-stl/

        sort(candidates.begin(),candidates.end()); //sorted the input array already so that we return combination in an lexicographic sorted order
        vector<vector<int>> ans;
        vector<int> ds;
        func(0,target,candidates,ds,ans);

        return ans;
    }
};

int main()
{

    Solution obj;
    vector<int> vect{1,1,1,2,2};
    vector<vector<int>> ans;
    int target=4;
    ans=obj.combinationSum2(vect,target);

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