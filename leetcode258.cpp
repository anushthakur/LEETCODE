//258.Add Digits


//for brute force refer this
//https://youtu.be/urZ7Jj2UXp0

//for optimal refer this(codebix)
//https://www.youtube.com/watch?v=rbAiLJ0z_bc&pp=ygUWYWRkIGRpZ2l0cyBicnV0ZSBmb3JjZQ%3D%3D

//CONSTRAINTS: 0 <= num <= 2^31 - 1
//FOLLOW UP: Could you do it without any loop/recursion in O(1) runtime?



//***************************BEST SOLUTION************************************
//TIME COMPLEXITY: O(1)
//SPACE COMPLEXITY: O(1)


class Solution {
public:
    int addDigits(int num) 
    {
        if(num==0) return 0; //this condition to be applied first otherwise num%9==0 will satisty too in case of 0 input

        else if(num%9==0) return 9;
        
        else return (num%9);
        
    }
};


//BRUTE FORCE O(C) here C is constant as maximum  value of num is 2^31 -1 which is a constant.
//O(C) does not mean O(1)  ****************************************

class Solution 
{
 public:
 int sum=0;
 int countdigits(int num)
 {
     int count=0;
      sum=0;
     while(num!=0)
     {
         sum+=num%10;
         num/=10;
         count++;
     }
     
    return count;
 }
    int addDigits(int num) 
    {
        while(countdigits(num)>1)
        {
            num=sum;
        }
        return sum;
    }
};

