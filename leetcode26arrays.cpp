#include<iostream>
using namespace std;


//26.Remove Duplicates from Sorted Array



/*
int main()
{
    // int n=10;
    // int a[n]={1,1,1,2,2,3,4,4,4,5};
    // int n=6;
    // int a[n]={1,1,1,2,2,3};

    //********************************TRIAL*****************************************************

    

    int n=9;
    int a[n]={0,0,1,1,1,1,2,3,3};
    
    for(int i=0,j=1;i<n && j<n;)
        {
            if(a[i]!=a[j])
            {
                i++,j++;
            }
            else
            {
                while(j<n)
                {
                    a[j]=a[j+1];
                    j++;
                }
                n--;
                j=i+1;
            }
        }

        for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
*/



/*

//*******************************SUBMISSION**********************************************************
//runtime error????,test cases passed....

class Solution 
{
    public:
    int removeDuplicates(vector<int>& nums) 
    {
        for(int i=0,j=1;i<nums.size() && j<nums.size();)
        {
            if(nums[i]!=nums[j])
            {
                i++,j++;
            }
            else
            {
                while(j<nums.size())
                {
                    nums[j]=nums[j+1];
                    j++;
                }
                nums.pop_back();
                j=i+1;
            }
        }
        return nums.size();
    }
};

*/

//******************************************************************************
//SACHIN'S TRIAL

/*

#include <iostream>
#include<vector>
using namespace std;
class Solution 
{
    public:
    int removeDuplicates(vector<int>& nums) 
    {
        for(int i=0,j=1;i<nums.size() && j<nums.size();)
        {
            if(nums[i]!=nums[j])
            {
                i++,j++;
            }
            else
            {
                while(j<nums.size())
                {
                    nums[j]=nums[j+1];
                    j++;
                }
                nums.pop_back();
                j=i+1;
            }
        }
        return nums.size();
    }
};

int main()
{
    Solution obj;
    vector <int> vect;
    int num[]={1,1,1,2,2,3,4,4,4,5};
    for(int i=0;i<(sizeof(num)/sizeof(num[0]));i++)
    {
        vect.push_back(num[i]);
    }
    obj.removeDuplicates(vect);

    //for each loop
    for(int j:vect)
    {
        cout<<j<<' '; //quotes
    }
}

*/

//******************************************************************************
//using another array to store(TAP ACADEMY YOUTUBE)

/*

#include<iostream>
using namespace std;

int main()
{
    int n=11;
    int a[]={1,1,1,2,2,2,3,4,4,4,5};
    int temp[n];

    int j=0,i;
    temp[j]=a[0];
    for( i=1;i<n;i++)
    {
        if(a[i]!=temp[j])
        {
            j++;
            temp[j]=a[i];

        }
    }
    for( i=0;i<=j;i++) cout<<temp[i]<<" ";
    
    return 0;
}

*/










//*******************************OPTIMAL SOLUTION***************************************************************
//(TAP ACADEMY YOUTUBE)


#include<iostream>
using namespace std;
int func(int arr[],int size)
{
    int i,j;
     for( i=0,j=1;j<size && i<size;j++)
    {
        if(arr[i]!=arr[j])
        {
            i++;
            arr[i]=arr[j];
        }
    }
    return i;
}
int main()
{
    int n=11;
    int arr[]={1,1,1,2,2,2,3,4,4,4,5};
    int r=func(arr,n);
    for(int i=0;i<=r;i++) cout<<arr[i]<<" ";
    return 0;
}



//********************************FINAL ACCEPTED SUBMISSION *********************************************************

/*

class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int j,i;
        for( i=0,j=1;i<nums.size() && j<nums.size();j++)
        {
            if(nums[i]!=nums[j])
            {
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};

*/


//****************************************************************************************************
//BEST SOLUTION ON LEETCODE

/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[count-1]!=nums[i]){
                nums[count]=nums[i];
                count++;

            }
        }
        return count;
    }
};
*/

//****************ABHILASHA DI**********************
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        for(int i=0; i<nums.size()-1; i++)
        {  //or nums.length-1
            if(nums[i]!=nums[i+1])
            {
                nums[count]=nums[i+1];
                count++;
            }    
            else
            {
                continue;
            }

           
        }
        return count;
    }
};
*/