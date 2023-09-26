//4.Median of two Sorted Arrays of Different Sizes
//TAKEUFORWARD
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution 
{
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int n1=nums1.size();
        int n2=nums2.size();
        int low=0,high=n1;

        while(low<=high)
        {
            int cut1=(low+high)/2;
            int cut2=((n1+n2+1)/2)-cut1;

            int l1=(cut1==0)?INT_MIN:nums1[cut1-1];
            int l2=(cut2==0)?INT_MIN:nums2[cut2-1];
            int r1=(cut1==n1)?INT_MAX:nums1[cut1];
            int r2=(cut2==n2)?INT_MAX:nums2[cut2];

            if(l1<=r2 && l2<=r1)
            {
                int max=l1>l2?l1:l2;
                int min=r1>r2?r2:r1;
                if((n1+n2)%2==0)
                {
                    double i=(max+min)/2.0;
                    return i;
                }
                else
                {
                    return max;
                }
            }

            else if(l1>r2) high=cut1-1;
            else low=cut1+1;

        }
        return 0.0; //incase nums1 and nums2 are not sorted and binary search couldn't ever find valid cuts

    }
};

int main()
{
    Solution obj;
    vector <int> vect1{1,2,5,6,8};
    vector <int> vect2{0,2,8,10};
    //final sorted array 0,1,2,2,5,6,8,8,10
    double median=obj.findMedianSortedArrays(vect1,vect2);
    cout<<"MEDIAN "<<median;

    return 0;
}

class Solution 
{
public:
//BETTER APPROACH
//TC:O(n+m)
//SC:O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)   {
       
       int size=nums1.size()+nums2.size();
        int mid1=(size/2)-1;
        int mid2=size/2;
        int i=0;
        int j=0;
        int ele1=-1,ele2=-1;
        int k=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]<nums2[j])
            {
                if(k==mid1)
                {
                    ele1=nums1[i];
                } 
                if(k==mid2)
                {
                    ele2=nums1[i];
                } 
                if(ele1 !=-1 && ele2 !=-1) break;
                i++;
                k++;
            }
            else
            {
                 if(k==mid1)
                {
                    ele1=nums2[j];
                } 
                if(k==mid2)
                {
                    ele2=nums2[j];
                } 
                 if(ele1 !=-1 && ele2 !=-1) break;
                j++;
                k++;

            }
        }
        while(i<nums1.size() )
        {
             if(ele1 !=-1 && ele2 !=-1) break;
             if(k==mid1)
                {
                    ele1=nums1[i];
                } 
                if(k==mid2)
                {
                    ele2=nums1[i];
                } 
            i++;
            k++;
        }
        while(j<nums2.size())
        {
             if(ele1 !=-1 && ele2 !=-1) break;
             if(k==mid1)
                {
                    ele1=nums2[j];
                } 
                if(k==mid2)
                {
                    ele2=nums2[j];
                } 
            j++;
            k++;
        }
            
            if(size%2==0)
            {
                return (ele1+ele2)/2.0;
            }
            else
            {
                return ele2;
            }
            
         }
};


/*
class Solution 
{
public:
//BRUTE FORCE
//TC:O(n+m)
//SC:O(n+m)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>ans(nums1.size()+nums2.size());
        int i=0;
        int j=0;
        int k=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]<nums2[j])
            {
                ans[k]=nums1[i];
                i++;
                k++;
            }
            else
            {
                ans[k]=nums2[j];
                j++;
                k++;

            }
        }
        while(i<nums1.size())
        {
            ans[k]=nums1[i];
            i++;
            k++;
        }
        while(j<nums2.size())
        {
            ans[k]=nums2[j];
            j++;
            k++;
        }
    int size=nums1.size()+nums2.size();
        if(size%2!=0)
        {
            //odd
            return ans[size/2];
            
        }
        else
        {
            return (ans[size/2] + ans[(size-1)/2] )/2.0;
        }
    }
};
*/


/*
class Solution 
{
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int n1=nums1.size();
        int n2=nums2.size();
        int low=0,high=n1;

        while(low<=high)
        {
            int cut1=(low+high)/2;
            int cut2=((n1+n2+1)/2)-cut1;

            int l1=(cut1==0)?INT_MIN:nums1[cut1-1];
            int l2=(cut2==0)?INT_MIN:nums2[cut2-1];
            int r1=(cut1==n1)?INT_MAX:nums1[cut1];
            int r2=(cut2==n2)?INT_MAX:nums2[cut2];

            if(l1<=r2 && l2<=r1)
            {
                int max=l1>l2?l1:l2;
                int min=r1>r2?r2:r1;
                if((n1+n2)%2==0)
                {
                    double i=(max+min)/2.0;
                    return i;
                }
                else
                {
                    return max;
                }
            }

            else if(l1>r2) high=cut1-1;
            else low=cut1+1;

        }
        return 0.0; //incase nums1 and nums2 are not sorted and binary search couldn't ever find valid cuts

    }
};
*/