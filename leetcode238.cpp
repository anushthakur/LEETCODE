//238.Product of array except self

#include<bits/stdc++.h>
using namespace std;

//Although question does not allow using divide operation
//error (findout) //trial
/*
class Solution 
{
 public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector <int> output(nums.size());
        
        int count=0;
        int ans=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
               
                count++;
                continue;
            }
            else 
            {
                
                ans*=nums[i];
            }
        }

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                count--;
            }
            if(count>0)
            {
                output[i]=0;
            }
            else if(nums[i]!=0)
            {
                int res=ans/nums[i];
                output[i]=res;
            }
            else output[i]=ans;
        }
        return output;
    }
};
*/

//chat gpt corrected error(trial)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size());

        int count = 0;
        int ans = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
                continue;
            }
            ans *= nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (count > 1) {
                output[i] = 0;
            } else if (count == 1 && nums[i] == 0) {
                output[i] = ans;
            } else if (count == 0) {
                output[i] = ans / nums[i];
            }
        }

        return output;
    }
};

//Above chat gpt solution has still some edge cases,which I corrected

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> output(nums.size(),0);
        //vector<int> output(nums.size(),-1); then case 2 output:-1,-1,9,-1,-1,which is wrong without this condition else if (count == 1 && nums[i] != 0) { output[i] = 0; }
                
            

        int count = 0;
        int ans = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
                continue;
            }
            ans *= nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (count > 1) {
                output[i] = 0;
            } else if (count == 1 && nums[i] == 0) {
                output[i] = ans;
            }
            else if (count == 1 && nums[i] != 0) {
                output[i] = 0;
            }
             else if (count == 0) {
                output[i] = ans / nums[i];
            }
        }

        return output;
    }
};




/*


Intuition
We can solve this question using Multiple Approaches. (Here I have explained all the possible solutions of this problem).

Solved using Array(Two Nested Loops). Brute Force Approach.
Solved using Dynamic Programming Approach(tabulation).
Solved using Dynamic Programming Approach(Space Optimization). Optimized Approach.
Approach
We can easily understand the All the approaches by seeing the code which is easy to understand with comments.

Complexity
Time complexity:
Time complexity is given in code comment.

Space complexity:
Space complexity is given in code comment.

Code


    Time Complexity : O(N^2), Where N is the size of the Array(nums). Here Two nested loop creates the time 
    complexity.

    Space complexity : O(1), Constant space. Extra space is only allocated for the Array(output), however the
    output does not count towards the space complexity.

    Solved using Array(Two Nested Loop). Brute Force Approach.

    Note : This will give TLE.

//***************************************** Approach 1 *****************************************

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;
        for(int i=0; i<n; i++){
            int product = 1;
            for(int j=0; j<n; j++){
                if(i == j) continue;
                product *= nums[j];
            }
            output.push_back(product);
        }
        return output;
    }
};








    Time Complexity : O(N), As we iterate the Array(nums) thrice. Where N = size of the array.

    Space complexity : O(N), Array(left_Product and right_Product) space. 

    Solved using Dynamic Programming Approach(tabulation).




//***************************************** Approach 2 *****************************************

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> left_Product(n);
        vector<int> right_Product(n);
        left_Product[0] = 1;
        for(int i=1; i<n; i++){
            left_Product[i] = left_Product[i-1] * nums[i-1];
        }
        right_Product[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            right_Product[i] = right_Product[i+1] * nums[i+1];
        }
        for(int i=0; i<n; i++){
            ans[i] = left_Product[i] * right_Product[i];
        }
        return ans;
    }
};








    Time Complexity : O(N), As we iterate the Array(nums) twice. Where N = size of the array.

    Space complexity : O(1), Constant space. Extra space is only allocated for the Array(output), however the
    output does not count towards the space complexity.

    Solved using Dynamic Programming Approach(Space Optimization). Optimized Approach.




//***************************************** Approach 3 *****************************************

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        output[0] = 1;
        for(int i=1; i<n; i++){
            output[i] = output[i-1] * nums[i-1];
        }
        int right = 1;
        for(int i=n-1; i>=0; i--){
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};


*/