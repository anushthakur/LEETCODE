//605. Can Place Flowers
//****************************TRIAL*************************************************
//RUNTIME ERROR
/*
#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {   int count=0;
        for(int i=0;i<flowerbed.size();i++)
        {   int prev=flowerbed[i-1],next=flowerbed[i+1];
            if(flowerbed[i]==0 && (prev==0 || i==0)&&(next==0 || i==flowerbed.size()-1)) 
            {
                count++;
                flowerbed[i]=1;
            }
        }
        if(count>=n) return true;
        else return false;
    }
};
int main()
{
    Solution obj;
    vector <int> vect{1,0,0,0,1};
    bool c=obj.canPlaceFlowers(vect,2);
    cout<<c;
    return 0;
}
*/


//*********************************************************************************
//ALGORITHMS MADE EASY
/*
//runtime error
class Solution 
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {   int count=0;
        for(int i=0;i<flowerbed.size();i++)
        {   
            if(flowerbed[i]==0) 
            {
                int prev=(flowerbed[i-1]==0 || i==0)?0:1;
                int next=(flowerbed[i+1]==0 || i==flowerbed.size()-1)?0:1;
                if( prev==0 && next==0 )
                {
                    flowerbed[i]=1;
                    count++;
                
                }
                
            }
        }
       if (count>=n )return true ;
       else return false;
        
    }
};
*/


//***************************SUBMITTED SOLUTION************************************
//java solution
/*
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n)
    {
         int count=0;
        for(int i=0;i<flowerbed.length;i++)
        {   
            if(flowerbed[i]==0) 
            {
                int prev;
                if(i==0) prev=0;
                else if(flowerbed[i-1]==0) prev=0;
                else prev=1;

                int next;
                if(i==flowerbed.length-1) next=0;
                else if(flowerbed[i+1]==0) next=0;
                else next=1;
                
               
                if( prev==0 && next==0 )
                {
                    flowerbed[i]=1;
                    count++;
                
                }
                
            }
        }
       if (count>=n )return true ;
       else return false;
        
        
    }
}
*/