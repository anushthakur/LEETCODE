//1491.Average Salary Excluding the Minimum and Maximum Salary


#include<iostream>
#include<vector>
#include<algorithm> //sort(),min(),max() inbuilt functions
#include<limits.h>
using namespace std;

//BOTH SOLUTIONS GIVING WRONG ANS IN TEST CASE:
//salary =[48000,59000,99000,13000,78000,45000,31000,17000,39000,37000,93000,77000,33000,28000,4000,54000,67000,6000,1000,11000]
//output:41111.00000
//expected:41111.11111


//TRIAL 
//TIME COMPLEXITY:O(n log n)
//SPACE COMPLEXITY:O(1)
class Solution 
{
  public:
    double average(vector<int>& salary) 
    {
        sort(salary.begin(),salary.end());
        int count=0;//int sum=0; //error was because of int data type
        double sum=0.0;
        for(int i=1;i<salary.size()-1;i++)
        {
            sum+=salary[i];
            count++;
        }
        return sum/count;
    }
};


//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(1)
class Solution 
{
  public:
    double average(vector<int>& salary) 
    {
       int maxS=INT_MIN;
       int minS=INT_MAX;
        int count=salary.size()-2;//int sum=0; //error was because of int data type
        double sum=0.0;

        for(int i=0;i<salary.size();i++)
        {
            minS=min(minS,salary[i]);
            maxS=max(maxS,salary[i]);
        }
        for(int i=0;i<salary.size();i++)
        {
            if(salary[i]!=maxS && salary[i]!=minS)
            sum+=salary[i];
            
        }
        
        return sum/count;
    }
};