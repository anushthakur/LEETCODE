//1901. Find a Peak Element II

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
   
/*
    APPROACH-1(NAIVE)
    1. We can iterate this matrix and try to find the peak elem by comparing
    it with its neighbours.
    2. We will have to take care of boundary cases.
    3. O(N^2)

    APPROACH-2(OPTIMAL)
    1. We will apply BINARY SEARCH in every row.
    2. Why Binary Search ?
    - Because in the question it is specified we have to do it in O(mlogm).
    - And if we see carefully peak elem will be greater than prev and the 
    next elems.
    - So we can actually decide the half that if the curr elem is not peak elem
    check the max elem in left of mid and right of mid 
    if leftOfMidHalf > rightOfMidHalf then our peak elem is on the
    left half otherwise vice-versa.
    3. In every row for every mid we will find upper , down , left , right.
    4. Will find max of vertical = max(upper,down) and 
    max of horizontal = max(left,right).
    5. We will also find max Elem in leftHalf of Mid by max(left, mat[i][0]);
    leftHalf of Mid by max(right, mat[i][col-1]);
    6. for peak if mat[i][mid]>max(vertical,horizontal) we have found our peak.
    7. If leftHalf > rightHalf then our peak elem is on left Side (high=mid-1)
    otherwise our peak elem is on the right side (low=mid+1)
    8. O(nlogm)
*/
//================================================================================================
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        //No of rows
        int cols = mat[0].size();
        //No of cols
        vector<int>ans;
        for(int i=0;i<rows;i++)
        //Traversing each row
        {
            int low =0;
            int high = cols-1;
            while(low<=high)
            //Applying BS in each row
            {
                int mid = (low+high)/2;

            //Checking all 4 directions
                int upper = i>0?mat[i][mid]:-1;
                int lower = i<rows-1?mat[i+1][mid]:-1;
                int left = mid>0?mat[i][mid-1]:-1;
                int right = mid<cols-1?mat[i][mid+1]:-1;

            //Checking max of vertical and horizonta direction
            //Not so imp steps
                int maxVertical = max(upper,lower);
                int maxHorizontal = max(left,right);

            //Finding max Half values
                int maxLeftHalf = max(left,mat[i][0]);
                int maxRightHalf = max(right,mat[i][cols-1]);

            //If our peak elem has been found
                if(mat[i][mid]>=max(maxVertical,maxHorizontal))
                {
                    ans.push_back(i);
                    ans.push_back(mid);
                    return ans;
                }
                else if(maxLeftHalf > maxRightHalf)
                //If left half is greater than right half then our peak elem
                //has greater prob of being in left half
                {
                    high = mid-1;
                }
                else
                //Greater prob of being in right half
                low=mid+1;
            }
        }
        return ans;
    }
};