//189. Rotate Array


/*CONCEPT BUILD UP,UNDERSTAND WHY IT'S WRONG...?

//=============================================
class Solution 
{
public:

    void  reversefun(vector<int>::iterator begin,vector<int>::iterator end,vector<int>& nums)
    {
        while(begin<end)
        {
            int temp=*begin;
            *begin=*end;
            *end=temp;
            begin++;
            end--;
        }
        
    }
    void rotate(vector<int>& nums, int k) 
    {
         k=k%nums.size();
        reversefun(nums.begin(),nums.begin()+(nums.size()-k),nums);

        reversefun(nums.begin()+(nums.size()-k),nums.end(),nums);
    
        reversefun(nums.begin(),nums.end(),nums);
    }
};
//===============================================

class Solution 
{
public:

    void  reversefun(vector<int>::iterator begin,vector<int>::iterator end,vector<int>& nums)
    {
        while(begin<end)
        {
            int temp=nums[begin-nums.begin()];
            nums[begin-nums.begin()]=nums[end-nums.begin()];
            nums[end-nums.begin()]=temp;
            begin++;
            end--;
        }
        
    }
    void rotate(vector<int>& nums, int k) 
    {
         k=k%nums.size();
        reversefun(nums.begin(),nums.begin()+(nums.size()-k),nums);

        reversefun(nums.begin()+(nums.size()-k),nums.end(),nums);
    
        reversefun(nums.begin(),nums.end(),nums);
    }
};

*/

//https://youtu.be/BHr381Guz3Y

//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(1)
#include<algorithm>
class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
         k=k%nums.size();
        reverse(nums.begin(),nums.begin()+(nums.size()-k));

        reverse(nums.begin()+(nums.size()-k),nums.end());
    
        reverse(nums.begin(),nums.end());
    }
};
//write your own reverse function instead of using library function



class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums, 0, nums.size() - k - 1);
        reverse(nums, nums.size() - k, nums.size() - 1);
        reverse(nums, 0, nums.size() - 1);
    }
};





//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(n)

class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        vector<int>v(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int z=(i+k)%nums.size();
            nums[z]=v[i];
        }

    }
};



















//wrong .....if can then figure out?
#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
 public:
    void rotate(vector<int>& nums, int k) 
    {
        int i=0;int j;
        int n=nums.size();

        if(n%2 != 0)
        {
           j =n-k-1;
        }
        else   j=n-k;
        
        int z=j;
        cout<<" z is"<< z<<endl;

        while(i<z && j<nums.size())
        {
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
            j++;
        }
    }
};


int main()
{
    vector<int> v{1,2,3,4,5,6,7};
    Solution obj;
    obj.rotate(v,3);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}

//ROTATE LEFT
//TAKE U FORWARD
/*
class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        k=k%nums.size();

        int temp[k];
        for(int i=0;i<k;i++)
        {
            temp[i]=nums[i]; 
        }

        for(int i=k;i<nums.size();i++) 
        {
            
            nums[i]=nums[i-k];
        }

        for(int i=nums.size()-k;i<nums.size();i++)
        {
            nums[i]=temp[i-(nums.size()-k)];
        }
    }
};

*/