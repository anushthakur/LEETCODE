//1642. Furthest Building You Can Reach

//youtube:fraz
//https://youtu.be/o84_EH4UJXc

/*
//CONCEPT:

f you have an array of size n and you want to build a heap from all items at once, Floyd's algorithm can do it with O(n) complexity. See Building a heap. This corresponds to the std::priority_queue constructors that accept a container parameter.

If you have an empty priority queue to which you want to add n items, one at a time, then the complexity is O(n * log(n)).

So if you have all of the items that will go into your queue before you build it, then the first method will be more efficient. You use the second method--adding items individually--when you need to maintain a queue: adding and removing elements over some time period.

Removing n items from the priority queue also is O(n * log(n)).

Documentation for std::priority_queue includes runtime complexity of all operations.
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//WITHOUT DP
//MAX_HEAP USING PRIORITY_QUEUE
//Priority Queue is the implementation of Max Heap by default. 

//TIME COMPLEXITY: O(n log n)
//SPACE COMPLEXITY:O(n) (in worst case to insert all of the elements in the priority_queue)
class Solution 
{
 public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        int i=0;
        priority_queue <int> q;
        for(i;i<heights.size()-1;i++) //IN WORST CASE TIME COMPLEXITY: O(n)
        {
            if(heights[i+1]<=heights[i]) continue;
            int d=heights[i+1]-heights[i];
            if(d<=bricks) 
            {   
                bricks-=d;
                q.push(d); //O(log n)
            }
            else if(ladders>0)
            {
                if(q.size()) // if priority_queue is not empty then only will work
                {
                    int x=q.top(); //max_heap,so its top contains maximum no. of bricks used in one move.
                    if(x>d)
                    {
                        bricks+=x;
                        q.pop(); //O(1)
                        q.push(d); //O(log n)
                        bricks-=d;
                    }
                   
                }
                 ladders--; //anyways in either of the cases one ladder is going to be used.
            }
            else break;
            
        }
        return i;
    }
};