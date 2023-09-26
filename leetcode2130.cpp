//2130. Maximum Twin Sum of a Linked List


//https://youtu.be/l91Q-Ds1RGE


//APPROACH 1

//TIME COMPLEXITY:O(2n)
//SPACE COMPLEXITY:O(n)

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
    int pairSum(ListNode* head) 
    {
        vector <int> vect;
        ListNode * ptr=head;
        while(ptr)
        {
            vect.push_back(ptr->val);
            ptr=ptr->next;
        }
        int i=0,j=vect.size()-1;
        int ans=0;
        while(i<j)
        {
            ans=max(ans,vect[i]+vect[j]);
            i++,j--;
        }
          return ans;
    }
};   



//APPROACH 2
//TIME COMPLEXITY:O(2n)
//SPACE COMPLEXITY:O(n/2)

  
 
class Solution 
{
 public:
    int pairSum(ListNode* head) 
    {
        int ans=0;
        int n=0;

        ListNode * ptr=head;
        while(ptr)
        {
            n++;
            ptr=ptr->next;
        }
        vector <int> v(n/2);
        ptr=head;
        int i=0;
        while(ptr)
        {
            if(i<n/2)
            {
                v[i]=ptr->val;
            }
            else
            {
                v[n-i-1] += ptr->val;
                ans=max(ans,v[n-i-1]);
            }
            ptr=ptr->next;
            i++;
            
        }
        return ans;
    }
};


//OPTIMAL SOLUTION
//APPROACH 3
//TIME COMPLEXITY:O(3n/2)
//SPACE COMPLEXITY:O(1)

class Solution 
{
public:
    int pairSum(ListNode* head) 
    {
        ListNode * slow=head,*fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;

        }

        //reversing half of the linked list
        ListNode* prev=NULL,*nxt,*curr=slow;
        while(curr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            
        }

        int ans=0;
        ListNode * i=head,*j=prev;
        while(i && j)
        {
            ans=max(ans,i->val + j->val);
            i=i->next;
            j=j->next;
        }
        return ans;
    }
};