//80.Remove Duplicates from Sorted Array ii
//YOUTUBE (code explainer)
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    int func(vector<int>& vect)
    {
       
        for(int i=1,j=1;i<vect.size();)
        {
            if(vect[i]==vect[i-1] && j<2) j++,i++;
            else if(vect[i]==vect[i-1]) 
            {
                vect.erase(vect.begin()+i);
               
            }
            else if(vect[i]!=vect[i-1])
            {
                j=1;
                i++; 
            }
           
        }
         return vect.size();
    }
};
int main()
{
    
    Solution obj;
    vector <int> vect{1,1,1,2,2,2,3,4,4,4,5};
    int r=obj.func(vect);
    for(int i=0;i<r;i++) cout<<vect[i]<<" ";
    
    return 0;
}


//*************Best solution on leetcode ******************
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int index = 1,count = 1;
        for(int i = 1 ; i< nums.size(); i++) 
        {
            if(nums[i] != nums[i-1]) 
            {
                nums[index] = nums[i];
                count = 1;
                index++;
            } 
            else  
            {
                if(count == 1) 
                {
                    nums[index] = nums[i];
                    count++;
                    index++;
                } 
                else 
                {
                    continue;
                }
            }
        }
        return index;
    }
};
*/