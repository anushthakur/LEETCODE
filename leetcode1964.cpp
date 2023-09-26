//1964. Find the Longest Valid Obstacle Course at Each Position(******IMP****)


//https://www.geeksforgeeks.org/upper_bound-in-cpp/
//this internally uses binary search

/*
upper_bound() is a standard library function in C++ defined in the header . It returns an iterator pointing to the first element in the range [first, last] that is greater than value, or last if no such element is found. The elements in the range shall already be sorted or at least partitioned with respect to val.
*/

//best explaination-->YOUTUBE(DEEPCODES)
//https://youtu.be/wGYQHu5--fE



//*************************************************************************************************

//*********************CONCEPT IMP******************************
/*

QUES. pointer minus pointer gives the index....

//ANSWER STACK OVERFLOW
//https://stackoverflow.com/questions/3238482/pointer-subtraction-confusion

Because everything in pointer-land is about offsets. When you say:

int array[10];
array[7] = 42;
What you're actually saying in the second line is:

*( &array[0] + 7 ) = 42;
Literally translated as:

* = "what's at"
(
  & = "the address of"
  array[0] = "the first slot in array"
  plus 7
)
set that thing to 42
And if we can add 7 to make the offset point to the right place, we need to be able to have the opposite in place, otherwise we don't have symmetry in our math. If:

&array[0] + 7 == &array[7]
Then, for sanity and symmetry:

&array[7] - &array[0] == 7

*/



//*********************************************************************************************
//CONCEPT
#include<iostream>
using namespace std;

int main()
{
    int array[10]={0};
   cout<< &array[7] - &array[0]; //giving the index
   //&array[7] - &array[0] == 7
    return 0;
}

//*************************************************************************************************

/*

//NOTE: upper1 - v.begin() gives the index.....



// CPP program to illustrate using
// std :: upper_bound with vectors
#include <bits/stdc++.h>
 
// Driver code
int main()
{
    std::vector<int> v{ 10, 20, 30, 40, 50 };
 
    // Print vector
    std::cout << "Vector contains :";
    for (int i = 0; i < v.size(); i++)
        std::cout << " " << v[i];
    std::cout << "\n";
 
    std::vector<int>::iterator upper1, upper2;
 
    // std :: upper_bound
    upper1 = std::upper_bound(v.begin(), v.end(), 35);
    upper2 = std::upper_bound(v.begin(), v.end(), 45);
 
    std::cout << "\nupper_bound for element 35 is at position : "
              << (upper1 - v.begin());
    std::cout << "\nupper_bound for element 45 is at position : "
              << (upper2 - v.begin());
 
    return 0;

//OUTPUT:

//Vector contains : 10 20 30 40 50
//upper_bound for element 35 is at position : 3
//upper_bound for element 45 is at position : 4




}

*/


//****************************************************************************
//****************BEST APPROACH**********************

//DYNAMIC PROGRAMMING

//BEST EXPLAINATION BY DEEPCODES //https://youtu.be/wGYQHu5--fE

//VIEW MORE SUBMITTED SOLUTIONS ON LEETCODE FOR BETTER UNDERSTANDING....

//TIME COMPLEXITY: O(n * log n) 

//[log n :taken by binary search and; n multiplied to it: as contributed by the loop]. 

//SPACE COMPLEXITY: O(n) because of the list vector that we made

#include<vector>
#include<algorithm>

class Solution 
{
 public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles)  
    {
        //DO CHECK AND SOLVE THESE FIRST FOR BETTER CONCEPT AND UNDERSTANDING:
        //problem of longest non decreasing subsequence
        //longest increasing subsequence
        //https://youtu.be/wGYQHu5--fE


        int n=obstacles.size();
        //lis which is name of another vector we are making,is acronym for longest increasing subsequence.
        vector <int> ans(n,1),lis; //length is 1 because that particular indexed element must be taken even when all of the other rules doesn't satisfy.


        for(int i=0;i<n;i++)
        {
            int idxToInsert=upper_bound(lis.begin(),lis.end(),obstacles[i])-lis.begin();

            if(idxToInsert==lis.size())
            {
                lis.push_back(obstacles[i]);
            }
            else
            {
                lis[idxToInsert]=obstacles[i];
            }
            ans[i]=idxToInsert+1;
        }

        return ans;
    }
};

