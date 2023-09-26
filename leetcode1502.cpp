//1502. Can Make Arithmetic Progression From Sequence

//concept:AP ka pehla element uss series ka minimum element hota hai
//concept:AP ka last element uss series ka maximum element hota hai

#include<bits/stdc++.h>
using namespace std;
//TRIAL
class Solution 
{
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end()); //O(nlogn)
        int diff=arr[1]-arr[0];
        for(int i=1;i<arr.size()-1;i++)
        {
            if(abs(arr[i]-arr[i+1])!=diff) //#include<cmath>
            {
                return false;
            }
        }
        return true;
    }
};



//==================== TRIAL 2 (TIME COMPLEXITY:O(n))===========================
//TRIAL 2 FOR OPTIMIZATION
//error [1,100] output=false,expected =true
class Solution 
{
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    { int n=arr.size();
        int maxele=arr[0],minele=arr[0],sum=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>maxele) maxele=arr[i];
            if(arr[i]<minele) minele=arr[i];
            sum+=arr[i];
        }
        //int ans=n*(minele+maxele)/2; //WRONG because in some cases like [1,2,4] which is not AP it is giving output true,but the correct output should be false.

        //int ans=(n/2)*(minele+maxele); //trying to calculate n/2 first
        //even after this adjustment there's error in [3,5,1] which should be true but my code is giving output false.
        //there is some other conceptual mistake

        //=========correction==============
        //Finding the average of the first and last term is the very first step and then Multiplying the average by the number of terms.
        if(n*((minele+maxele)/2)==sum) return true;
        else return false;
    }
};


//TRIAL 2 FOR OPTIMIZATION //error in concept maybe
class Solution 
{
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    { int n=arr.size();
        int maxele=arr[0],minele=arr[0],sum=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>maxele) maxele=arr[i];
            if(arr[i]<minele) minele=arr[i];
            sum+=arr[i];
        }
        //int ans=n*(minele+maxele)/2; //WRONG because in some cases like [1,2,4] which is not AP it is giving output true,but the correct output should be false.

        int ans=(n/2)*(minele+maxele); //n/2 has to be calculated first
        //even after this adjustment there's error in [3,5,1] which should be true but my code is giving output false.
        //there is some other conceptual mistake
        if(ans==sum) return true;
        else return false;
    }
};

/*
//trying to debug

bool canMakeArithmeticProgression(vector<int>& arr) 
    { int n=arr.size();
        int maxele=arr[0],minele=arr[0],sum=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>maxele) maxele=arr[i];
            if(arr[i]<minele) minele=arr[i];
            sum+=arr[i];
        }
        //int ans=n*(minele+maxele)/2; //wrong
        int ans=(n/2)*(minele+maxele); //n/2 has to be calculated first
        cout<<maxele<<endl;
        cout<<minele<<endl;
        cout<<ans<<endl;
        cout<<sum<<endl;
        if(ans==sum) return true;
        else return false;
    }

    int main()
    {
        vector<int> vect {1,2,4};
       cout<< canMakeArithmeticProgression(vect);
        return 0;
    }
    */










   //======================youtube comment==========================


   //bhaiya ,yeh summation of n terms of AP jisme first aur last terms ka use karke sum nikalte hain,yeh concept galat hai kya mera,please give a look once....//error in test case [1,100] ,output=false, expected =true
class Solution 
{
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    { int n=arr.size();
        int maxele=arr[0],minele=arr[0],sum=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>maxele) maxele=arr[i];
            if(arr[i]<minele) minele=arr[i];
            sum+=arr[i];
        }

//==========TRIAL 1==================
        //int ans=n*(minele+maxele)/2; //WRONG because in  test case [1,2,4] which is not AP ,it is giving output true,but the correct output should be false.


//==============TRIAL 2================
        //int ans=(n/2)*(minele+maxele); //trying to calculate n/2 first
        //even after this adjustment there's error in [3,5,1] which should be true but my code is giving output false.
       

        //============TRIAL 3==============
        //Finding the average of the first and last term is the very first step and then Multiplying the average by the number of terms.

        if(n*((minele+maxele)/2)==sum) return true;
        else return false;
    }
};                 //In all the ways of calculating some test case is not getting satisfied.....So,is my concept wrong???Please help