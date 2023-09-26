//43.Multiply strings
//IMP TYPE

//trial (not complete)
class Solution 
{
public:
    string multiply(string num1, string num2) 
    {
        int first=0;
        int second=0;

        for(int i=num1.size()-1;i>=0;i--)
        {
            first += i* 10 + (num1[i]-48);
        }

        for(int i=num2.size()-1;i>=0;i--)
        {
            second += i* 10 + (num2[i]-48);
        }
        //string ans = first*second; //error:no viable conversion from 'int' to 'std::string'.
        int x=first*second;
        string ans="";
        int res=0;
        while(x!=0)
        {
            res=x%10;
            ans+=(res + '0');
            x/=10;
        }
        for(int i=0,j=ans.length()-1;i<j;i++,j--) 
        {
            char temp=ans[i];
            ans[i]=ans[j];
            ans[j]=temp;
        }
        return ans;
    }
};