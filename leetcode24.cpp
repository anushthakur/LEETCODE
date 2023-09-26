//24. Swap Nodes in Pairs

//TRIAL
//QUESTION KE HISAAB SE NOT WHAT WAS WANTED(BECAUSE NODE SWAP KARNA HAI NA KI VALUES)
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

 /*
 //CONCEPT

 Line 1034: Char 9: runtime error: reference binding to null pointer of type 'int' (stl_vector.h)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/stl_vector.h:1043:9

//The problem is that you've created an empty vector and then trying to access that empty vector's elements leading to undefined behavior.
//To solve this you can make the vector to be of a particular size at the time of its creation
 */
class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* ptr=head;
        vector <int> v;
        for(;ptr!=NULL;ptr=ptr->next)
        {
            //error undefined behaviour
            //v[i]=ptr->val;
            //i++;
            v.push_back(ptr->val);
        }

        for(int i=0,j=1;i<v.size()-1 && j<v.size();)
        {
            int temp=v[i];
            v[i]=v[j];
            v[j]=temp;
            i+=2;
            j=i+1;
        }

     int i=0;
        for(ptr=head;ptr!=NULL && i<v.size();ptr=ptr->next,i++)
        {
            ptr->val=v[i];
        }
        return head;
    }
};


//LEETCODE SOLUTION

//Time complexity:O(n)
//Space complexity:O(n)

class Solution 
{
 public:
    ListNode* swapPairs(ListNode* head) 
    {
    if (!head || !head->next) 
    {
        return head;
    }
    ListNode* next = head->next;
    head->next = swapPairs(next->next);
    next->next = head;
    return next;
}

};

//ITERATIVE AWY
//https://youtu.be/jCE4XmjEbx8
//Time complexity:O(n)
//Space complexity:O(1)


class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(head==nullptr || head->next==nullptr) return head;

        ListNode * prev=nullptr,* curr=head,* nxt=head->next;

        head=head->next;

        while(curr && nxt)
        {
            if(prev)
            {
                prev->next=nxt;
            }
            curr->next=nxt->next;
            nxt->next=curr;
            prev=curr;
            curr=curr->next;
            if(curr)nxt=curr->next;
            
        }
        return head;
    }
};

//RECURSIVE WAY
//https://youtu.be/8yLiGS4ntHw

class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(head==NULL || head->next==NULL) return head;

         //A = head
         //B = head->next
         //C = head->next->next

         ListNode* temp=head->next;
         head->next=swapPairs(head->next->next);
         temp->next=head;

    return temp;
    }
   


};