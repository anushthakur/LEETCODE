//649. Dota2 Senate


//https://youtu.be/eny6bOqxeqE
//DeepCodes (YOUTUBE)

//TIME COMPLEXITY:O(n+ n^2) => O(n^2)
//SPACE COMPLEXITY:O(n)

//best strategy is to ban the closest opposite party senator as it will save one member of our party from being banned.(i.e. it can preserve person from the same party.)
//total number of rounds needed to be conducted to conclude the game: log N with base 2.

/*
//n ,there are n people in round one and let us assume it will take k rounds to terminate the voting programme.
//n/2 ,people remaining after round one
//n/4 ,people remaining after round two
//n/8
//...
//n/2^k ,till when just 1 person is left

//that is n=2^k
//=> log n=k log 2 with base 2
//=>k=log n with base 2
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*

In round 1,voting takes place n/2 times
In round 2,voting takes place n/4 times
In round 2,voting takes place n/8 times
In round 2,voting takes place n/16 times
In round 2,voting takes place n/32 times

//total no. of times voting takes place : n/2 + n/4 + n/8 + n/16 + n/32 + .....(SUM OF INFINITE TERMS OF G.P.)
//SUM OF INFINITE TERMS OF G.P.=> a/(1-r)  =>  (n/2) / (1- 1/2) =>n.

*/

class Solution 
{
 public:
    void ban(string& senate,vector <bool>& banned,char toban,int index)//for each vote this ban function gets called and voting takes place n times and time complexity of ban() is O(n),so final time complexity:O(n^2).
    {
        while(true) //In worst case O(n) time complexity
        {
            if(senate[index]==toban && !banned[index])
            {
                banned[index]=true;
                break;
            }
            index=(index+1)%senate.size(); //so that i does not go out of bounds,if it goes it will again be 0.
        }

   }

    string predictPartyVictory(string senate) 
    {
        int n=senate.size();
        vector<bool> banned(n,false); //O(n) space complexity

        int rcount=0,dcount=0;

        for(int i=0;i<n;i++) //O(n) time complexity
        {
            if(senate[i]=='R') rcount++;
            else dcount++;
        }
        int i=0;
        while(rcount>0 && dcount>0)
        {
            if(!banned[i])
            {
                if(senate[i]=='R')
                {
                    ban(senate,banned,'D',(i+1) % senate.size()); //so that i does not go out of bounds,if it goes it will again be 0.
                    dcount--;
                }
                else
                {
                    ban(senate,banned,'R',(i+1) % senate.size());
                    rcount--;
                }
            }
            i = (i+1) % senate.size();
        }
        return rcount==0 ? "Dire":"Radiant";
    }
};