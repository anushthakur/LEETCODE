//881. Boats to Save People



//DON'T REFER TO YOUR BRUTE FORCE TRIAL(IT'S ALL WRONG)
//********************************************************************************************
//trial (***BAHUT GANDI VALI TLE***time limit exceeded)

/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
  public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        int boat=0;
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
       
        while(i<=j)
        {   
           
            if(people[i]==limit)
            {
                return people.size();
            }
            else if(people[j]==limit)
            {
                boat++;
                j--;
            }
            
            if(people[i]+people[j]==limit ) 
            {
                boat++;
                i++,j--;
            }
            if((people[i]+people[j]<limit && i==j)) boat++; 
            else if(people[i]+people[j]>limit)
            {
                j--;
            }
            else i++;

        }
        return boat;
    }
};

int main()
{   
    vector <int> vect{3,2,2,1};
    int limit=3;
    Solution obj;
    int res=obj.numRescueBoats(vect,limit);
    cout<<"minimum no. of boats needed "<<res;
    return 0;
}

*/


//*********WRONG*******************TWO POINTER APPROACH(trial)***************************************************
//WRONG >>>>>>> bug in input 3,2,3,2,2 and limit=6
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
  public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        int boat=0;
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
       
        while(i<j)
        {   
             if(people[i]+people[j]==limit)
             {
                 boat++;
                 i++,j--;
             }
             else if(people[i]+people[j]>limit)
             {
                 j--;
                 boat++;
             }
             else i++; //error because of this //scroll down for the correct optimal solution
       

        }
        if(i==j) boat++;
        return boat;
    }
};

int main()
{   
    vector <int> vect{3,2,2,1};
    int limit=3;
    Solution obj;
    int res=obj.numRescueBoats(vect,limit);
    cout<<"minimum no. of boats needed "<<res;
    return 0;
}
*/



//****************************************************************************************
//ANUBHAV GHOSH
/*
//BRUTE FORCE(not yet completely coded)
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

class Solution 
{
  public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        int boat=0; //3,2,3,2,2
      for(int i=0;i<people.size();i++)
      {
         if(people[i]==limit)
         {
            boat++;
            i++;
         }
         if(people[i]<limit)
         {
            vector<int>::iterator it;
            it=find(people.begin()+i+1,people.end(),(limit-people[i]));
            if(it !=people.end() || i==people.size()-1)
            {
                
                boat++;
                people.erase(it);
                

            }
         }
      }
      return boat;
    }
};

int main()
{   
    //vector <int> vect{3,2,2,1};
    vector <int> vect{3,2,3,2,2};
    //int limit=3;
    int limit=6; 
    Solution obj;
    int res=obj.numRescueBoats(vect,limit);
    cout<<"minimum no. of boats needed "<<res;
    return 0;
}
*/

//*************************************************************************************
//FINAL CORRECT SOLUTION USING TWO POINTER
//TIME COMPLEXITY:O(n*log n)
//SPACE COMPLEXITY:O(log n) (of sorting a vector)

/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
  public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        int boat=0;
        sort(people.begin(),people.end()); //O(n*log n)
        int i=0,j=people.size()-1;
       
        while(i<j) //O(n)
        {   
             if(people[i]+people[j]<=limit)
             {
                 boat++;
                 i++,j--;
             }
             else if(people[i]+people[j]>limit)
             {
                 j--;
                 boat++;
             }
             
       

        }
        if(i==j) boat++; //or we can change while(i<=j)
        return boat;
    }
};

int main()
{   
    //vector <int> vect{3,2,2,1};
    vector <int> vect{3,2,3,2,2};
    //int limit=3;
    int limit=6; 
    Solution obj;
    int res=obj.numRescueBoats(vect,limit);
    cout<<"minimum no. of boats needed "<<res;
    return 0;
}

*/


//BRUTE FORCE 
//https://aknottymathematician.github.io/dsa/boat-to-save-people/#:~:text=defnumRe,eturnans


