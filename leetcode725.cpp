//725. Split Linked List in Parts


#include<bits/stdc++.h>
using namespace std;


class Solution 
{
public:
//codestorywithMIK
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        //find length of LL

        ListNode* ptr=head;
        int count=0;
        while(ptr)
        {
            count++;
            ptr=ptr->next;
        }

        int min=count/k;
        int additional=count%k;

        vector<ListNode*> result(k,NULL);

        ptr=head;
        ListNode* prev=NULL;

        for(int i=0;i<k && ptr!=NULL;i++)
        {
            result[i]=ptr;
            for(int c=1;c<=min+(additional>0)?1:0 ;c++)
            {
                prev=ptr;
                ptr=ptr->next;
            }
            prev->next=NULL;
            additional--;
        }
        return result;

    }
};


 // Definition for singly-linked list.
  struct ListNode 
  {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

 /*

 //TRIAL (WRONG) FIGURE OUT?
class Solution 
//head=[1,2,3] k=5
//my output:[[1,2,3],[2,3],[3],[3],[3],[3]]
//expected:[[1],[2],[3],[],[]]
{
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        vector<ListNode*> ans;
        //edge case
        if(head==NULL) return ans;


        ListNode* ptr=head;
        int count=0;
        while(ptr)
        {
            count++;
            ptr=ptr->next;
        }

        vector <int> v(k);
        int min=count/k;
        int additional=count%k;

        for(int i=0;i<k && additional>0;additional--,i++)
        {
            v[i]+=1;
            additional--;
        }


        ptr=head;
        ans.push_back(ptr);
        for(int i=0;i<k && ptr!=NULL;i++)
        {
            int c=v[i];
            while(c)
            {
                ptr=ptr->next;
                c--;
            }
            ans.push_back(ptr);
        }
        return ans;
    }
};
*/