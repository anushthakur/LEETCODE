//1359. Count All Valid Pickup and Delivery Options


//BRUTE FORCE: Take out all permutations and out of them reject the ones which do not satisfy the given condition.But this would be exponential T.C. and surely give TLE.

//===================================================================================

//codestorywithMIK
//better way using combinatronics and maths instead of DP
class Solution 
{
public:
    int countOrders(int n) 
    {
        //DOUBT: har step mein M se mod lene ke bajaye ,sirf last mein ek bar return karne se pehle karen toh overflow hoga.

        int M=1e9 + 7;
        if(n==1) return 1;

        long long result=1; //n=1

        for(int i=2;i<=n;i++)
        {
            int spaces=(i-1)*2+1;
            int possibility=spaces*(spaces+1)/2;
            result*=possibility;
            result%=M;
        }
        return result;
    }
};