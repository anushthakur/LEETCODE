//27. Remove Element

//trial all wrong java code
import java.util.Arrays;
class Solution 
{
    public int removeElement(int[] nums, int val) 
    {
        if(nums.length==0 || (nums.length==1 && nums[0]==val) ) return 0;
        if(nums.length==1 && nums[0]!=val) return 1;
        int j=nums.length-1;
        while(nums[j]==val) j--;
        int i;
        boolean flag=false;
        for(i=0;i<j;)
        {
            if(nums[i]==val)
            {
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                j--; i++;
                while(nums[j]==val) j--;
            }
            else
            {
                i++;
            }
        }
         return i+1;
    }
}

