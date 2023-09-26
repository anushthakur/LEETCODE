//1802. Maximum Value at a Given Index in a Bounded Array


//BINARY SEARCH

//https://youtu.be/MjpAAE3-hYg
class Solution 
{
public:
    int maxValue(int n, int index, int maxSum) 
    {
        long r=n-index-1;
        long l=index;

        long high=maxSum;
        long low=1;

        long ans=0;

        while(low<=high)
        {
            long mid=(high-low)/2 + low;
            long sum=mid;
            long rs=0; //sum on right
            long ls=0; //sum on left
            long  m=mid-1;

            if(r<=m)
            {
                rs=m*(m+1)/2 - (m-r)*(m-r+1)/2;
            }
            else
            {
                rs=m*(m+1)/2 + 1*(r-m);
            }
            if(l<=m)
            {
                ls=m*(m+1)/2 - (m-l)*(m-l+1)/2;
            }
            else
            {
                ls=m*(m+1)/2 + 1*(l-m);
            }

            sum+=ls+rs;

            if(sum<=maxSum)
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};



















//trial
//error n=3,index=2,maxSum=18    output=6,expected=7
class Solution 
{
public:
    int maxValue(int n, int index, int maxSum) 
    {
        int x=maxSum/n;
        int rem=maxSum-(x*n);
        int addon= rem/2;
        
        return x+addon;

    }
};


//TRIAL UPDATION
//error Input n =9,index =3,maxSum =16,  Output=5, Expected=3

class Solution 
{
public:
    int maxValue(int n, int index, int maxSum) 
    {
        //edge case
        if(n==1) return maxSum;

        int x=maxSum/n;
        int rem=maxSum-(x*n);
         int addon= rem/2;
        if(rem==0)  //if index:  mid ke left side hai to (index)th element plus 1 hoga aur (index+2)th element ek kam ho jayega i.e. - 1 hoga.
        //if index: mid par ya mid ke right hai,toh (index)th element + 1 aur (index-2)th element - 1 ho jayega.
        {
            return x+addon+1;
        }
        else if(rem%2!=0) return x+addon+1;
       
        else
        {
           return x+addon;
        }
        

    }
};