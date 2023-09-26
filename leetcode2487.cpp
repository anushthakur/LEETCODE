//2487. Remove Nodes From Linked List


#include<vector>
#include<iostream>
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
 //TLE
class Solution 
{
public:
    ListNode* removeNodes(ListNode* head) 
    {
        vector<int> array;
        for(ListNode* ptr=head;ptr!=NULL;ptr=ptr->next)
        {
            array.push_back(ptr->val);
        }

        for(int i=0;i<array.size()-1;i++)
        {
            for(int j=i+1;j<array.size();j++)
            {
                if(array[i]<array[j])
                {
                    array[i]=0;
                    break;
                }
            }
        }
        ListNode* ptr=head;
        for(int i=0;i<array.size();i++)
        {
            if(array[i]!=0)
            {
                ptr->val=array[i];
                if(i!=array.size()-1) ptr=ptr->next;
                else ptr->next=NULL;
            }
        }
        return head;
    }
};
*/

class Solution 
{
public:
    ListNode* removeNodes(ListNode* head) 
    {
        vector<int> array;
        for(ListNode* ptr=head;ptr!=NULL;ptr=ptr->next)
        {
            array.push_back(ptr->val);
        }

        //int arr[array.size()]={0}; //error:variable-sized object may not be initialized.
        int n=array.size();
       vector<int> arr(n,0);

        arr[array.size()-1]=array[array.size()-1];

        int k=array.size()-2;

        for(int i=array.size()-2;i>=0;i--)
        {
            if(array[i]>=arr[k+1])
            {
                arr[k]=array[i];
                k--;
            }
             
        }

        int i=0;
        while(arr[i]==0) i++;

        ListNode* ptr=head;
        for(;i<arr.size();i++)
        {
            ptr->val=arr[i];
            if(i!=arr.size()-1) ptr=ptr->next;
            else ptr->next=NULL;
        }

            return head;
    }
};