//234. Palindrome Linked List


#include<iostream>
#include<vector>
using namespace std;

 //Definition for singly-linked list.
  struct ListNode 
  {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution 
{
public:
//BRUTE FORCE
//TC:O(N)
//SC:O(N)
    bool isPalindrome(ListNode* head) 
    {
        ListNode* ptr=head;
        vector<int>v;
        while(ptr)
        {
            v.push_back(ptr->val);
            ptr=ptr->next;

        }
    int i=0;
    int j=v.size()-1;
        while(i<=j)
        {
            if(v[i]!=v[j]) return false;
            i++;
            j--;
        }
        return true;


    }
};