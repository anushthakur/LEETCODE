//Move all zeroes to end of array

//wrong way (because see the expected output format)
class Solution
{
public:
	void pushZerosToEnd(int arr[], int n) 
	{
	    int i=0;
	    int j=n-1;
	    
	    while(i<j)
	    {
	        if(arr[i] != 0) i++;
	        if(arr[j]==0) j--;
	        if(arr[i]==0 && arr[j]!=0 && i<j)
	        {
	            int temp=arr[i];
	            arr[i]=arr[j];
	            arr[j]=temp;
	        }
	    }
	}
};