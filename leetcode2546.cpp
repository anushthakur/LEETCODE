//2546. Apply Bitwise Operations to Make Strings Equal
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool makeStringsEqual(string s, string target) 
    {
        //THINKCODE
        //https://youtu.be/8ce7elPDc6U

        //MY NOTES===> 
        //                 XOR   OR
        //   0     0  =>    0     0
        //   0     1  =>    1     1
        //   1     0  =>    1     1
        //   1     1  =>    0     1

        //for converting 0 to 1 => 0 ka 1 ke saath xor/or kuch bhi
        //for converting 1 to 0=> 1 ka 1 ke saath XOR =>0 and 1 ka 1 ke saath OR.
        //1 ka 0 ke saath OR lo ya XOR lo 0 kabhi nhi milega.
        //aur 1 to 1 ya 0 to 0 ka conversion ka koi sense hi nhi banta.
        
    //edge case
        if(s==target) return true;


    //jitne bhi 0 1 ya 1 0 vale mismatch hain vo 1 1 ki presence se door ho jayenge.
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1' && target[i]=='1') return true;
        }

    //agar 0 1 ya 1 0 vala ek mismatch hai toh 1 0 ya 0 1 respectively mismatch bhi hona hi chahiye tabhi true ka case banega as unme se ek mismatch intermediate step mein 1 1 mein convert ho jayega.
    bool flag=false,flg=false;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1' && target[i]=='0') flag=true;

             if(s[i]=='0' && target[i]=='1') flg=true;

        }    

        if(flag && flg) return true;

        return false;
    }
};