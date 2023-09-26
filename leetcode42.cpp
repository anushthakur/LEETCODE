//42.Trapping rain water


//TAP ACADEMY
/*

//JAVA CODE:

//********************************APPROACH 1*************************************************
//APPROACH 1: O(n^2) time complexity and space complexity O(1)
//TIME LIMIT EXCEEDED
class Solution 
{
    
    public  int trap(int[] height) 
    {
        int res=0;
        for(int i=1;i<=height.length-2;i++)
        {
            int lb=height[i];
            for(int j=0;j<=i-1;j++)
            {
                if(height[j]>lb)
                {
                    lb=height[j];
                }
            }
            int rb=height[i];
            for(int j=i+1;j<height.length;j++)
            {
                if(height[j]>rb)
                {
                    rb=height[j];
                }
            }
            int wl;
            if(rb<lb)
            {
                wl=rb;
            }
            else wl=lb;
            int tw=wl-height[i];
            res+=tw;
        }
        return res;

    }
}
*/




//********************************APPROACH 2*************************************************


//APPROACH 2: O(n) time complexity and space complexity O(n)

/*
class Solution 
{
    
    public int trap(int[] height) 
    {
        int res=0;

        int[] lb=new int[height.length];
        int[] rb=new int[height.length];

        lb[0]=height[0];
        for(int i=1;i<=height.length-2;i++)
        {
            lb[i]=Math.max(height[i],lb[i-1]);
        }

        rb[height.length-1]=height[height.length-1];
        for(int i=height.length-2;i>=0;i--)
        {
            rb[i]=Math.max(height[i],rb[i+1]);
        }

        for(int i=1;i<=height.length-2;i++)
        {
            res+=Math.min(lb[i],rb[i])-height[i];
        }
        return res;
    }
}

*/



//********************************APPROACH 3*************************************************

//APPROACH 3: O(n) time complexity and space complexity O(1)
//MOST OPTIMAL SOLUTION(using two pointer approach)

/*
class Solution 
{
    
    public int trap(int[] height) 
    {
        int res=0;
        int l=0;
        int r=height.length-1;
        int lhb=height[0];
        int rhb=height[height.length-1];

        while(l<=r)
        {
            if(lhb<=rhb)
            {
                if(height[l]>=lhb)
                {
                    lhb=height[l];
                }
                else
                {
                    res+=lhb-height[l];
                }
                l++;
            }
            else
            {
                if(height[r]>=rhb)
                {
                    rhb=height[r];
                }
                else
                {
                    res+=rhb-height[r];
                }
                r--;
            }
        }
        return res;
    }
}

*/
