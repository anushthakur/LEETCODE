//1318. Minimum Flips to Make a OR b Equal to c

//https://youtu.be/Gx4-uOkopMA
//codestorywithMIK

//method 1

class Solution 
{
public:
    int minFlips(int a, int b, int c)
    {
        int flip=0;
        while(a!=0 || b!=0 || c!=0)
        {
            if((c & 1)==1)
            {
                if((a&1)==0 &&  (b&1)==0) flip++;
            }
            else
            {
                if((a&1)==1)
                {
                    flip++;
                }
                if((b&1)==1)
                {
                    flip++;
                }
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return flip;
    }
};


//method 2

//In C++, the __builtin_popcount() function is a built-in function provided by some compilers (such as GCC and Clang) as an optimization intrinsic. It calculates the number of set (or 1) bits in an integer.


class Solution 
{
public:
    int minFlips(int a, int b, int c) 
    {  //gcc copiler ka builtin function which counts the number of 1's in the binary representation of a decimal number.
        return __builtin_popcount(((a|b)^c)) + __builtin_popcount(a&b); //error a=7,b=7,c=7,output=3,expected=0
    }
};
//correct

class Solution 
{
public:
    int minFlips(int a, int b, int c) 
    {
        return __builtin_popcount(((a|b)^c)) + __builtin_popcount(((a|b)^c)&(a&b));
    }
};