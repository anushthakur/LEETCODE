//141. Linked List Cycle
#include<bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
  struct ListNode
  {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


/*
 //brute force
 //TC: O(N)
 //SC:O(N)
class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        unordered_map<ListNode*,int> mp;

       ListNode* ptr=head;
      for(ptr;ptr!=NULL;ptr=ptr->next)
      {
          if(mp.find(ptr)!=mp.end())
          {
              return true;
          }
          else
          {
              mp.insert({ptr,ptr->val});
          }
      }
      return false;
        
    }
};
*/


//TC:O(N)
// SC:O(1)
class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        if(head==NULL || head->next==NULL) return false;

        else
        {
            ListNode* slow=head;
            ListNode* fast=head;

            //while(fast->next!=NULL || fast->next->next!=NULL) runtime error: member access within null pointer of type 'ListNode' (solution.cpp) BECAUSE OF THIS :fast->next->next!=NULL
            while(fast->next && fast->next->next)
            {
                fast=fast->next->next; 
                slow=slow->next;        

                if(fast==slow) return true; //kyonki agar loop present hoga toh hi fast aur slow ki ek hi node ko point karne ki possibility hogi,loop nhi hoga toh kabhi nhi hogi aur ek time par fast null ko point karega.

                //fast toh humesha slow se aage hi rahega par sirf usi case mein slow ke barabar hoga jab vo kisi karan vash slow ke peeche aa jaye aur fir faasla cover karle,that means ghoom kar peeche aaye that means only when there is an existence of a loop.
            }
            return false;
        }
    }
};