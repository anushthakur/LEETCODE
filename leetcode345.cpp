//345. Reverse Vowels of a String

#include<iostream>
#include<string>
using namespace std;
class Solution 
{
 public:
 bool isVowel(char &  ch)
 {
     if(ch=='a' || ch=='A' || ch=='e'  || ch=='E'  || ch=='i'  || ch=='I'  || ch=='o'  || ch=='O'  || ch=='u'  || ch=='U')
     {
         return true;
     }
     else return false;
 }


    string reverseVowels(string s) 
    {
        
        for(int i=0,j=s.size()-1;i<j;)
        {
           if(!isVowel(s[j])) j--;

          else if(!isVowel(s[i])) i++;

          else 
            {
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                i++;
                j--;
            }

        }

        
        return s;
    }
};

/*
void fun(int arr[],int n)
{
    int i=0,j=n-1;
    while(i<j)
    {
        swap(arr[i],arr[j]);
        i++;j--; 
    }
}
int main()
{
    int arr[5]={1,2,3,4,5};
    fun(arr,5);
    cout<<arr[1];
    return 0;
}
*/
