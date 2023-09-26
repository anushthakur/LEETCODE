//11.Container with most water

//**************TRIAL(TWO POINTER APPROACH)********************************

//WRONG ANSWER AS NOT PROPERLY THOUGHT AND APPROACH NOT CONCEPT WISE CORRECTLY IMPLEMENTED AS j ITERATOR HAS NOT BEEN MOVED AT ALL IN THIS TRIAL OF YOURS.

#include<iostream>
#include<vector>
using namespace std;
/*
//CORRECTION TO BE DONE :one of i or j should be moved towards the other depending upon which is smaller between height[i] and height[j],refer pepcoding youtube channel for concept and explaination
class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int res=0;
        int cal=0;
        
        int i=0,j=height.size()-1;
        for(i,j;i<j;i++)
        {
            if(height[i]<=height[j])
            {
               cal=(j-i)*height[i];
            }
            else
            {
                cal=(j-i)*height[j];
            }
            if(cal>res)
            {
                res=cal;
            }
            
        }
        return res;
    }
};
*/



//*****************ACCEPTED CODE******************************************************
//Mastering programming,pepcoding
//REFER pepcoding(CONCEPT)
//Time complexity O(n) space complexity O(1)

class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int res=0;
        int cal=0;
        
        int i=0,j=height.size()-1;
        while(i<j)
        {
            if(height[i]<=height[j])
            {
               cal=(j-i)*height[i];
               i++;
            }
            else
            {
                cal=(j-i)*height[j];
                j--;
            }
            if(cal>res)
            {
                res=cal;
            }
            
        } 
        return res;
    }
};

//******************************************************************************************
//Time complexity O(n^2) ,Brute force approach
//TIME LIMIT EXCEEDED
/*
class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int res=0;
        int cal=0;
        
        
        for(int i=0;i<height.size()-1;i++)
        {
            for(int j=i+1;j<height.size();j++)
            {
                if(height[i]<=height[j])
            {
               cal=(j-i)*height[i];
               
            }
            else
            {
                cal=(j-i)*height[j];
                 
            }
            if(cal>res)
            {
                res=cal;
            }
            
            }
            
        }
        return res;
    }
}; 
*/


int main()
{
    Solution obj;
    vector <int> vect{1,8,6,2,5,4,8,3,7};
    int res=obj.maxArea(vect);
    cout<<"The maximum amount of water a container can store is :"<<res;
    return 0;
}
