//61. Rotate List
#include<bits/stdc++.h>
using namespace std;

//NOT THE BEST METHOD


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
    vector<int>array;
    ListNode* rotateRight(ListNode* head, int k) 
    {

        //edge case
        if(head==NULL) return head;

        
        for(ListNode* ptr=head;ptr!=NULL;ptr=ptr->next)
        {
            array.push_back(ptr->val);
        }
        vector<int>v(array.size());

        for(int i=0;i<array.size();i++)
        {
            v[(i+k)%array.size()]=array[i];
        }
        
        ListNode* ptr= new ListNode();
        head=ptr;
        int i=0;
        while(i<v.size())
        {
            ptr->val=v[i];
            if(i!=v.size()-1)
            {
                 ptr->next=new ListNode();
                ptr=ptr->next;
            }
           i++;
        }
        ptr->next=NULL;
        return head;
    }
};