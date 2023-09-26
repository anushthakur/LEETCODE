//2193. Minimum Number of Moves to Make Palindrome

//YOUTUBE:cracking FAANG for concept
//https://youtu.be/2Vcdjb-H8yA



//code is not the best as it is not using DP but still refer //https://youtu.be/EpuC64ClV8k
//find optimal solution on youtube for this question....using DP


#include<algorithm> //for using swap() in c++
#include<iostream>

//SOLUTION WITHOUT DYNAMIC PROGRAMMING
//TWO POINTER APPROACH
class Solution 
{
 public:
 
    int minMovesToMakePalindrome(string s) 
    {
        int n=s.size();
        int lt=0,rt=n-1,ans=0;

        while(lt<rt)
        {
            int l=lt,r=rt;
            while(s[l]!=s[r])
            {
                r--;
            }
            if(l==r)
            {
                swap(s[r+1],s[r]);
                ans++;
                continue;
            }
            else
            {
                while(r<rt)
                {
                    swap(s[r],s[r+1]);
                    ans++;
                    r++;
                }
            }
            lt++,rt--;
        }
        return ans;
    }
};


using namespace std;

int main(){
    
    return 0;
}