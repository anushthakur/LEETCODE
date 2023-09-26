//142. Linked List Cycle II

#include<iostream>
using namespace std;


//   Definition for singly-linked list.
  struct ListNode 
  {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

/*


 // Floyd's Cycle Detection algorithm
 //brute force
 TC:O(N)
 SC:O(N)
class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        int i=0;
        unordered_map<ListNode*,int>mp;
        ListNode* ptr=head;
        for(;ptr!=NULL;ptr=ptr->next)
        {
             if(mp.find(ptr)!=mp.end()) 
             {
                 int a=mp[ptr];
                 return ptr;
             } 
             else
             {
                 mp.insert({ptr,i++});
             }
        }
        return NULL;

       
    }
};
*/

//code with alisha
//TC:O(N)
//SC:O(1)
class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(head==NULL || head->next==NULL) return NULL;
        else
        {
            ListNode* slow=head;
            ListNode* fast=head;
            bool cyclefound=false;
            

            while(fast->next && fast->next->next)
            {
               
                fast=fast->next->next;
                slow=slow->next;

                if(fast==slow)
                {
                   cyclefound=true;
                   break;
                }
            }
            if(cyclefound==false)return NULL;
            else
            {
                fast=head;
                while(fast!=slow)
                {
                    fast=fast->next;
                    slow=slow->next;
                }
                return fast;
            }
        }
        
    }
};