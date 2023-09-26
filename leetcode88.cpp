//88. Merge Sorted Array

//TRIAL
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        vector<int>ref(m);
        for(int i=0;i<m;i++)
        {
            ref[i]=nums1[i];
        }
        //using two pointers
        int i=0;//pointer traversing ref
        int j=0;//pointer traversing nums2
        int k=0; //pointer traversing nums1 which will be our result array
        while(i<ref.size()  && j<nums2.size() && k<nums1.size())
        {
            if(ref[i]<=nums2[j])
            {
                nums1[k]=ref[i];
                k++;
                i++;
            }
            else if(ref[i]>nums2[j])
            {
                nums1[k]=nums2[j];
                k++;
                j++;
            }
        }

        while(i<ref.size())
        {
            nums1[k]=ref[i];
                k++;
                i++;
        }

        while(j<nums2.size())
        {
            nums1[k]=nums2[j];
                k++;
                j++;
        }

        

    }
};