//2086. Minimum Number of Food Buckets to Feed the Hamsters

#include<bits/stdc++.h>
using namespace std;

//TRIAL
//TIME COMPLEXITY:O(n)
//SPACE COMPLEXITY:O(1)

class Solution 
{
 public:
    int minimumBuckets(string& hamsters) 
    {
        char prev, next;
        int count=0;
        for(int i=0;i<hamsters.size();i++)
        {
            
            if(hamsters[i]=='H')
            {
                 if(i==0) prev='H'; 
                 else prev=hamsters[i-1];

                 if(i==hamsters.size()-1) next='H';
                 else next=hamsters[i+1];

                 if(prev=='H' && next=='H') return -1;

                 if(prev=='.' && next=='.')
                 {
                     //next='P'; //mistake,instead of next we need to modify our string,so correct is to use hamsters[i+1]='P;
                     hamsters[i+1]='P';
                     count++;
                     cout<<"first count executed"<<endl;
                     continue;
                 }

                 if(prev=='.' && next=='P') continue;
                 else if(prev=='.') 
                 {
                    //prev='P'; //mistake
                    hamsters[i-1]='P';
                    count++;
                    cout<<"second count executed"<<endl;
                    continue;
                 }

                if(next=='.' && prev=='P') continue;
                 else if(next=='.')
                 {
                    //next='P'; //mistake
                    hamsters[i+1]='P';
                    count++;
                    cout<<"third count executed"<<endl;
                    continue;
                 } 
            }
        }
        return count;
    }
};


int main()
{

    Solution obj;
    string str=".H.H.";
    cout<<obj.minimumBuckets(str);
    return 0;
}