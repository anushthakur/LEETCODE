//50. Pow(x, n)

//SOLVE IT AGAIN BY YOURSELF

//wrong ,why???
class Solution 
{
public:

    double myPow(double x, int n) 
    {
        if(n==1) return x;
        if(n==0) return x;
        if(x==0) return 1.0;
        if(x<0) return 1/x*myPow(x,n-1);

        return x*myPow(x,n-1);
         

    }
};

//=======================================================================
//whatsapp dsa peer

double power(double x,long long int y)
    {
        double ans=1.0;
        while(y>0)
        {
            if(y%2==0)
            {
                x=x*x;
                y=y>>1;
            }
            else
            {
                y=y-1;
                ans=ans*x;
            }
        }
        return ans;
    }
    double myPow(double x, int n) {
        long long int y=abs(n);
        double ans=power(x,y);
        if(n<0)
        ans=1/ans;

        return ans;
    }


    //=========================================================================
    //correct

    class Solution 
{
public:
   double power(double x,long long int y)
    {
        double ans=1.0;
        while(y>0)
        {
            if(y%2==0)
            {
                x=x*x;
                y=y>>1;
            }
            else
            {
                y=y-1;
                ans=ans*x;
            }
        }
        return ans;
    }
    double myPow(double x, int n) 
    {
        long long int y=abs(n);
        double ans=power(x,y);
        if(n<0)
        ans=1/ans;

        return ans;
    } 
};