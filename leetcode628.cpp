//628. Maximum Product of Three Numbers

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

//error nums = [-100,-98,-1,2,3,4]
//Output 24
//Expected 39200
//here in this error,the largest product is achieved by multiplying the two smallest negative numbers (-100 and -98) with the largest positive number (4)

/*'
To fix this, you need to consider two scenarios when calculating the maximum product:

1)Product of the three largest elements: This is already implemented in the code.
2)Product of the two smallest negative numbers and the largest positive number: You need to check for this scenario and compare it with the product calculated in step 1.
*/



//error for a test case(as not complete concept)
//TRY TO DO THIS BY WRITING YOUR OWN SORT
class Solution 
{
public:
    int maximumProduct(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end(),greater<int>()); //sorting in descending order
        //LEARN MORE ABOUT COMPARATORS..
        int product=nums[0]*nums[1]*nums[2];
        return product;

    }
};


//=========================corrected trial=========================================

class Solution 
{
public:
    int maximumProduct(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end(),greater<int>());

        int product1=nums[0]*nums[1]*nums[2]; 
        //error nums = [-100,-98,-1,2,3,4]
        //Output 24
        //Expected 39200
        int product2=INT_MIN;
        if(nums[0]>0 && nums[nums.size()-2]<0 && nums[nums.size()-1]<0) product2=nums[0]*nums[nums.size()-2]*nums[nums.size()-1];


        /*Product of the three largest elements: This is already implemented in the code.
          Product of the two smallest negative numbers and the largest positive number: You need to check for this scenario and compare it with the product calculated in the step earlier.
*/
        return (product1>product2)?product1:product2;

    }
};