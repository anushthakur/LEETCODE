//206. Reverse Linked List


#include<iostream>
using namespace std;
 // Definition for singly-linked list.
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
    //TRIAL
public:
    ListNode* reverseList(ListNode* head) 
    {

        //edge case
        if(head==NULL || head->next==NULL) return head;

       ListNode* prev;
       ListNode* curr;
       ListNode* nxt;
        
        
       prev=head;
       curr=head;
       nxt=head->next;

    //for the very first time only
       prev->next=NULL;
       curr=nxt;
       nxt=nxt->next;

    //for rest of the others
    while(nxt)
    {
        curr->next=prev;
        prev=curr;
        curr=nxt;
        nxt=nxt->next;

    }
    curr->next=prev;

    return curr;

    
        
    }
};


