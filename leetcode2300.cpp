//2300. Successful Pairs of Spells and Potions

//************************************************************************
//SYNTAX HELP:
//vector<int> v(100, 5); // Creates object with 100 elements.// Each of the elements is initialized to 5.
//vector<int> v(100, 0);  100 is the number of elements.The elements are initialized with zero values.
//vector<int> v(100); // 100 is the number of elements.



//************************************************************************************************
//BRUTE FORCE TRIAL (TIME LIMIT EXCEEDED)
/*
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        vector <int> ans;
        for(int i=0;i<spells.size();i++)
        {
            long long count=0;
            for(int j=0;j<potions.size();j++)
            {
                long long product=(long long)potions[j]*spells[i];
                if(product>=success)
                {
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};    
 */             

//**************************//OPTIMAL WAY(YOUTUBE: DEEPCODES)***************************************************

//https://www.geeksforgeeks.org/analysis-of-time-and-space-complexity-of-stl-containers/

/*
//TIME COMPLEXITY:O(m*log m) + O(n* (log m))
//finally: O(n+m(log m))

//SPACE COMPLEXITY: O(log m),space complexity of sorting a vector,m is size of vector.

class Solution 
{
 public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        vector<int>ans; //Though we are using this ans vector but we won't consider it into our space complexity because return type mentioned by ques. itself is  vector<int>.

        sort(potions.begin(), potions.end());
        
        for (int i = 0; i < spells.size(); i++) //O(n)
        {

            int l = 0, h = potions.size()-1, successStartIdx = potions.size();
            while (l <= h) //O(log m) of binary search 
            {
                
                int mid = l + (h-l)/2;
                long long curr = (long long)spells[i] * potions[mid];
                // cout << potions[mid] << " "; 
                
                if (curr >= success) 
                {
                    successStartIdx = mid;
                    h = mid - 1;
                }
                else 
                {
                    l = mid + 1;
                }
            }
            ans.push_back(potions.size() - successStartIdx);

        }
        
        return ans;
    }
};

*/

//*****************************************************************************
