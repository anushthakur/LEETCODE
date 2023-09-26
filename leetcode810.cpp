//810. Chalkboard XOR Game

#include<bits/stdc++.h>
using namespace std;

//Also, if any player starts their turn with the bitwise XOR of all the elements of the chalkboard equal to 0, then that player wins.
//that is why nums = [1,2,3],Output: true,  kyonki 1^2=3 and 3^3=0 toh already array jo usko mili element hatane ke liye uska xor zero aa rha tha toh return zero karenge.

//incomplete code without fully question understanding
//so, error
class Solution 
{
public:
    bool xorGame(vector<int>& nums) 
    {
        //odd size : alice always losing
        int n=nums.size();
        if(n%2!=0) return false; 

        //storing frequencies of every element
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        vector<int> count;
        for(const auto & x:mp)
        {
            if(x.second>2) return false;
            if(x.second==2) count.push_back(x.first);
        }
        if(count.size()>1) return false;
        else return true;
        

    }
};

//======================UPDATION=============================
//new error faced
//0,0,0,1 expected=true,my answer=false

class Solution 
{
public:
    bool xorGame(vector<int>& nums) 
    {
        //odd size but xor alreardy zero
        int cal=0;
        for(int i=0;i<nums.size();i++)
        {
            cal^=nums[i];
        }
        if(cal==0) return true;


        //otherwise odd size : alice always losing
        int n=nums.size();
        if(n%2!=0) return false; 

        //storing frequencies of every element
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        vector<int> count;
        for(const auto & x:mp)
        {
            if(x.second>2) return false;
            if(x.second==2) count.push_back(x.first);
        }
        if(count.size()>1) return false;
        else return true;
        
    }
};

//==============updation 2===========================

//1,0,0,1,1,1,1,1,1,0   output : false , expected: true

class Solution 
{
public:
    bool xorGame(vector<int>& nums) 
    {
        //odd size but xor alreardy zero
        int cal=0;
        int countzeros=0;
        for(int i=0;i<nums.size();i++)
        {
            cal^=nums[i];
            if(nums[i]==0) countzeros++;
        }
        if(cal==0) return true;

        bool flag=false;
        if(countzeros==nums.size()-1) flag=true;

        //otherwise odd size : alice always losing
        int n=nums.size();
        if(n%2!=0) return false; 

        //storing frequencies of every element
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        vector<int> count;
        for(const auto & x:mp)
        {
            if(x.second>2) 
            {
               if(flag==true) return true;
               else return false;
            }
            if(x.second==2) count.push_back(x.first);
        }
        if(count.size()>1) return false;
        else return true;
        
    }
};

//updation 3
// error 1,0,0,1,1,1,1,1,1,0   expected true, my output false
class Solution 
{
public:
//same numbers ka xor, when that particular number's frequency is odd is not zero but equal to the same number
    //2 2 2 2 2 => xor = 2 , because 2 occurred 5 times which is odd
    bool xorGame(vector<int>& nums) 
    {
        //odd size but xor alreardy zero
        int cal=0;
        int countzeros=0;
        for(int i=0;i<nums.size();i++)
        {
            cal^=nums[i];
            if(nums[i]==0) countzeros++;
        }
        if(cal==0) return true;

        bool flag=false;
        if(countzeros==nums.size()-1) flag=true;

        //otherwise odd size : alice always losing
        int n=nums.size();
        if(n%2!=0) return false; 

        //storing frequencies of every element
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        vector<int> count,anu;
        for(const auto & x:mp)
        {
            if(x.second>2) 
            {
                anu.push_back(x.first);
                if(anu.size()==2 && mp[0]%2!=0) return true;

               if(flag==true) return true;
               else return false;
            }
            if(x.second==2) count.push_back(x.first);
        }
        if(count.size()>1)
        {
            if(count.size()==2 && mp[0]%2!=0) return true;
            else return false;
        } 
        else return true;
        
    }
};


//updation on going...
class Solution 
{
public:
//same numbers ka xor, when that particular number's frequency is odd, is not zero but equal to the same number
    //2 2 2 2 2 => xor = 2 , because 2 occurred 5 times which is odd
    // 5 5 5 1 1 1 1 1 = 5
    bool xorGame(vector<int>& nums) 
    {
        //odd size but xor alreardy zero
        int cal=0;
        int countzeros=0;    
        for(int i=0;i<nums.size();i++)
        {
            cal^=nums[i];
            if(nums[i]==0) countzeros++;
        }
        if(cal==0) return true;

        bool flag=false;
        if(countzeros==nums.size()-1) flag=true;

        //otherwise odd size : alice always losing
        int n=nums.size();
        if(n%2!=0) return false; 

        //storing frequencies of every element
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        vector<int> count,anu;
        for(const auto & x:mp)
        {
            if(x.second>2) 
            {
                anu.push_back(x.first);
                if(anu.size()==2 && mp[0]%2!=0) return true;

               if(flag==true) return true;
               else return false;
            }
            if(x.second==2) count.push_back(x.first);
        }
        if(count.size()>1)
        {
            if(count.size()==2 && mp[0]%2!=0) return true;
            else return false;
        } 
        else return true;
        
    }
}; 











//=========================correct(leetcode peer)====================================

class Solution 
{
public:    
    bool xorGame(vector<int>& nums) 
    {
        int xorr=0;
        int n=nums.size();

        if(n==1 && nums[0]!=0)
        return false;

        else
        {
            for(int i=0; i<n; i++)
            {
                xorr = (xorr ^ nums[i]);
            }
            if(xorr==0)
            return true;
        }

        if(n % 2 == 1)
        return false;
        else
        return true;
    }
};