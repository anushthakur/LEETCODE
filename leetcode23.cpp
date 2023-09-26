//23. Merge k Sorted Lists

#include<bits/stdc++.h>
using namespace std;


 struct ListNode 
 {
    int val;
   ListNode *next;
    ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


 /*
 //RUNTIME ERROR
class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int n=lists.size();
        vector <int> arr;
        
        ListNode* ptr;
        for(int i=0;i<n;i++)
        {
            ptr=lists[i];
            while(ptr!=NULL)
            {
             arr.push_back(ptr->val);
             ptr=ptr->next;
            }
            
        }

        sort(arr.begin(),arr.end());

        ListNode head; //YAHAN SHAYAD KUCH GADBAD HAI....
        head.val=arr[0];
        ptr=&head;
        
        for(int i=1;i<n;i++)
        {
            
            ptr->next=new ListNode;
            ptr=ptr->next;
            ptr->val=arr[i];
        }
        ptr->next=NULL;

        return &head;
    }
};
*/


//CHATGPT CORRECTED
class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int n = lists.size();
        vector<int> arr;
        
        ListNode* ptr;
        for (int i = 0; i < n; i++) 
        {
            ptr = lists[i];
            while (ptr != nullptr) 
            {
                arr.push_back(ptr->val);
                ptr = ptr->next;
            }
        }

        sort(arr.begin(), arr.end());

        ListNode* dummyHead = new ListNode();
        ListNode* curr = dummyHead;
        
        for (int i = 0; i < arr.size(); i++) 
        {
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }
        curr->next = nullptr;

        return dummyHead->next;
    }
};
