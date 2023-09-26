//2126. Destroying Asteroids

//THINK ABOUT HOW TO RETURN ORDER OF ASTEROIDS???(extra task)

//************TRIAL****************************

//given constraints' limit 10^5,so maximum time complexity allowed O(nlogn)
//approach:sort then try(intuition)

//RUNTIME ERROR
/*
#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
 public:
    void merge(vector<int>& asteroids,int l,int m,int r)
    {
        int i=l,j=m+1,k=l;
        int size=(r-l)+1;
        vector<int> temp(size,0);
        while(i<=m && j<=r)
        {
            if(asteroids[i]<=asteroids[j])
            {
                temp[k]=asteroids[i];
                i++,k++;
            }
            else
            {
                temp[k]=asteroids[j];
                j++,k++;
            }
            
        }
        while (i<=m)
        {
           temp[k]=asteroids[i];
                i++,k++;
        }
         while (j<=r)
        {
           temp[k]=asteroids[j];
                j++,k++;
        }
        for(int p=l;p<=r;p++)
        {
            asteroids[p]=temp[p-l];
        }
        
    }
    vector<int> mergeSort(vector<int>& asteroids,int l,int r)
    {
        if(l<r)
        {
            int m=(l+((r-l)/2));
            mergeSort(asteroids,l,m);
            mergeSort(asteroids,m+1,r);
            merge(asteroids,l,m,r);
        }
        return asteroids;
    }
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) 
    {
        mergeSort(asteroids,0,asteroids.size()-1);
        int flag=0;
        for(int i=0;i<asteroids.size();i++)
        {
            if(asteroids[i]<=mass)
            {
                mass+=asteroids[i];
            }
            else
            {
                return false;
            }
        }
        return true;
    } 
    
};

int main()
{
    Solution obj;
    int mass=10;
    vector<int> asteroids{3,9,19,5,21};
    bool check=obj.asteroidsDestroyed(mass,asteroids);
    cout<<check;
    return 0;
}
*/

//****************************************************************************
/*
//RUNTIME ERROR??
class Solution 
{
 public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) 
    {
        int n = sizeof(asteroids) / sizeof(asteroids[0]);
        sort(asteroids.begin(), asteroids.begin() + n);
        long m=mass;
        int flag=0;
        for(int i=0;i<asteroids.size();i++)
        {
            if(asteroids[i]<=m)
            {
                m+=asteroids[i];
            }
            else
            {
                return false;
            }
        }
        return true;

    } 
    
};
*/

/*
//RUNTIME ERROR??
class Solution 
{
 public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) 
    {
        int n = sizeof(asteroids) / sizeof(int);
        sort(asteroids.begin(), asteroids.begin() + n);
        long m=mass;
        int flag=0;
        for(int i=0;i<asteroids.size();i++)
        {
            if(asteroids[i]<=m)
            {
                m+=asteroids[i];
            }
            else
            {
                return false;
            }
        }
        return true;

    } 
    
};
*/



//***************ACCEPTED JAVA CODE*******************
//PEPCODING
/*
class Solution 
{
    public boolean asteroidsDestroyed(int mass, int[] asteroids) 
    {
        long m=mass;
        Arrays.sort(asteroids);
        for(int i=0;i<asteroids.length;i++)
        {
            if(m-asteroids[i]<0)
            {
                return false;
            }
            else m+=asteroids[i];
        }
        return true;
    }
}
*/