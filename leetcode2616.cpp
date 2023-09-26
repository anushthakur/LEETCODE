//2616. Minimize the Maximum Difference of Pairs
#include<bits/stdc++.h>
using namespace std;
class Solution 
{  //vanAmsen
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        
        int left = 0, right = nums.back() - nums.front();
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (can_form_pairs(nums, mid, p)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    

    bool can_form_pairs(const vector<int>& nums, int mid, int p) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1 && count < p;) {
            if (nums[i+1] - nums[i] <= mid) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        return count >= p;
    }
};
/*
Binary Search on Maximum Difference
Instead of trying to find pairs directly, we'll conduct a binary search on the potential range of maximum differences. The range we'll be searching within spans from 0 to the difference between the largest and smallest values in the sorted array.

For every potential maximum difference, denoted as mid\text{mid}mid, we'll implement a greedy strategy to determine if we can create the requisite number of pairs.

Greedy Pairing
Given a maximum difference mid\text{mid}mid, we traverse the sorted array and attempt to form pairs in a greedy manner. Whenever two consecutive numbers in the array have a difference that is equal to or less than mid\text{mid}mid, we pair them together. If, by the end of our traversal, we have been able to form the required number of pairs, it signifies that our mid\text{mid}mid value is feasible.

*/