//1232. Check If It Is a Straight Line

//TRIAL

#include<bits/stdc++.h>
using namespace std;
//error : WRONG FOR : [[2,1],[4,2],[6,3]] output=false expected=true
//BECAUSE THIS TRIAL CODE IS IGNORANT ,I HAVE MISSED OUT A LOT OF TEST CASES AS IT'S INCOMPLETE
class Solution 
{
 public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        int ans1=0;
        int ans2=0;
        for(int i=0;i<coordinates.size();i++)
        {
            
                ans1+=coordinates[i][0];
                ans2+=coordinates[i][1];
            
        }
        int first1=coordinates[0][0];
        int first2=coordinates[0][1];
        int del1=(first1-1)*(first1)/2;
        int del2=(first2-1)*(first2)/2;
        int last1=coordinates[coordinates.size()-1][0];
        int last2=coordinates[coordinates.size()-1][1];
        int sum1=last1*(last1 + 1)/2;
        int sum2=last2*(last2 + 1)/2;

        if(ans1==(sum1 - del1) && ans2==(sum2-del2)) return true;
        else return false;
        
    }
};

//**********************CORRECT CONCEPT *******************************
//codestorywithMIK

class Solution 
{

public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        int n=coordinates.size();
        int dy=coordinates[0][1]-coordinates[1][1]; //y2-y1
        int dx=coordinates[0][0]-coordinates[1][0]; //x2-x1

        //slope=dy/dx

        for(int i=2;i<n;i++)
        {
            int dyi=coordinates[i][1]-coordinates[0][1];
            int dxi=coordinates[i][0]-coordinates[0][0];

            //slope=dyi/dxi

            //dy/dx = dyi/dxi
            //or
            //dy * dxi = dyi * dx

            if(dy * dxi != dyi * dx) return false;
        }
        return true;
    }
};