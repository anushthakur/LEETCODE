//138. Copy List with Random Pointer

#include<iostream>
#include<unordered_map>
using namespace std;

//APPROACH 2
class Solution 
{
public:

//codestorywithMIK
    //TC:O(N)
    //SC:O(1) extra space as O(N) which was used in creating n extra nodes was themselves used as result 


    Node* copyRandomList(Node* head) 
    {
        //edge case
        if(head==NULL) return NULL;

        Node* curr=head;
        

        //1)insert new nodes in between original LL.
        while(curr!=NULL)
        {
            Node* curnext=curr->next; 
            curr->next=new Node(curr->val);
            curr->next->next=curnext;

            curr=curnext;

        }

    //2)Deep copy of Random pointers
    curr=head;
    while(curr && curr->next)
    {
        if(curr->random ==NULL)
        {
            curr->next->random==NULL;
        }

        else
        {
            curr->next->random=curr->random->next;
        }

        curr=curr->next->next;
    }

    //3)separate both the linked lists.
    curr=head;
    Node* newhead=curr->next;
    Node* ans=curr->next;

    while(curr && newhead)
    {
        curr->next=(curr->next==NULL)?NULL:curr->next->next;
        newhead->next=(newhead->next==NULL)?NULL:newhead->next->next;

        curr=curr->next;
        newhead=newhead->next;

    }



    return ans;

        
    }
};




// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};



/*
//APPROACH 1
class Solution 
{
public:
    //TC: O(N)
    //SC: O(N)
    Node* copyRandomList(Node* head) 
    {
        //edge case
        if(head==NULL) return NULL;

        else
        {
            unordered_map <Node*,Node*> mp;

            Node* curr=head;
            Node* newhead=NULL;
            Node* prev=NULL;


            while(curr)
            {
                Node* temp=new Node(curr->val);
                mp[curr]=temp; //storing correspondence in map
                if(newhead==NULL)
                {
                    newhead=temp;
                    prev=newhead;
                }
                else
                {
                    prev->next=temp;
                    prev=temp;
                }
                curr=curr->next;
            }


            //deep copying random pointers
            curr=head;
            Node* dl=newhead;

            while(curr)
            {
                if(curr->random==NULL) dl->random=NULL;

                else
                {
                   dl->random=mp[curr->random]; 
                }

                curr=curr->next;
                dl=dl->next;
            }
            
            return newhead;

        }
        


    }
};
*/
