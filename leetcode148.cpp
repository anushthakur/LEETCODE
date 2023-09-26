//148. Sort List
#include<bits/stdc++.h>
using namespace std;


//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution 
{
public:

ListNode* Mid(ListNode* head)
{
    ListNode* slow=head;
    ListNode* fast=head->next; // ListNode* fast=head; it will give address sainitizer error
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

ListNode* merge(ListNode* firstLL,ListNode* secondLL)
{
   

    ListNode* ans=new ListNode();
    ListNode* temp=ans;

    if(firstLL==NULL) return secondLL;
    if(secondLL==NULL) return firstLL;

    while(firstLL!=NULL && secondLL!=NULL)
    {
        if(firstLL->val < secondLL->val)
        {
            temp->next=firstLL;
            temp=firstLL;
            firstLL=firstLL->next;
        }
        else 
        {
             temp->next=secondLL;
            temp=secondLL;
            secondLL=secondLL->next;
        }
    }

    while(firstLL!=NULL)
    {
        temp->next=firstLL;
        temp=firstLL;
        firstLL=firstLL->next;
    }

    while(secondLL!=NULL)
    {
        temp->next=secondLL;
        temp=secondLL;
        secondLL=secondLL->next;
    }
    ans=ans->next;
    return ans;
}


    ListNode* sortList(ListNode* head) 
    {
        //if(head->next!=NULL || head!=NULL) return head; //(error)watch its sequence

        if(head==NULL || head->next==NULL) return head;

        ListNode* mid=Mid(head);
        ListNode* firstLL=head;
        ListNode* secondLL=mid->next;
        mid->next=NULL;

        firstLL=sortList(firstLL);
        secondLL=sortList(secondLL);

        ListNode* result= merge(firstLL,secondLL);
        return result;
   
    }
};