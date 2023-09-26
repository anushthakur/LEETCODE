//2645.Minimum additions to make valid string

//trial wrong ans

class Solution {
public:
    int addMinimum(string word) {


unordered_map  <char,int> mp;
unordered_map <char,int>:: iterator it;
unordered_map  <char,int> :: iterator x=mp.begin();
mp['a']=0;
mp['b']=0;
mp['c']=0;
for(int i=0;i<word.length();i++)
{
   mp[(word[i])]+=1;

}

it=max_element(mp.begin(),mp.end());
int sum=0;
while(x != mp.end())
{
sum+=(( it->second) - (x->second));
x++;
}

return sum;
        
    }
};