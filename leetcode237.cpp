//237. Delete Node in a Linked List

//codestorywithMIK
#include<iostream>
using namespace std;

 
 struct ListNode 
 {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution 
{
public:
    void deleteNode(ListNode* node)
    {
        ListNode* prev=node;
        ListNode* ptr;

        for(ptr=node->next;ptr->next!=NULL;ptr=ptr->next)
        {
            prev->val=ptr->val;
            prev=prev->next;
        }
        prev->val=ptr->val;
        prev->next=NULL;
    }
};