//2336. Smallest Number in Infinite Set



/** QUES.
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */


//CONCEPT
//https://stackoverflow.com/questions/13718465/what-does-it-mean-to-return-a-reference
/*

int& foo () {
    static int x = 0;
    return x;
}

//...
int main()
{
    foo() = 2;
    cout << foo();
}
//would be legal and print out 2, because foo() = 2 modifies the actual value returned by foo.

//However:

int& doit () {
    int x = 0;
    return x;
}
//would be illegal (well, accessing the returned value would), because x is destroyed when the method exits, so you'd be left with a dangling reference.

*/




//****************YOUTUBE(codestorywithMIK)***************************************


#include<iostream>
#include<vector>
using namespace std;



//************BRUTE FORCE******************************
//TIME COMPLEXITY:
//SPACE COMPLEXITY:

class SmallestInfiniteSet 
{
 public:
     vector <bool> nums;
     int i; //points current smallest always
    SmallestInfiniteSet() 
    {
        nums=vector <bool> (1001,true);
        i=1;
    }
    
    int popSmallest() 
    {
        int result=i;
        nums[i]=false;
        for(int j=i+1;j<1001;j++)
        {
            if(nums[j]==true)
            {
                i=j;
                break;
            }
        }
        return result;
    }
    
    void addBack(int num) 
    {
        nums[num]=true;
        if(num<i) i=num;
        
    }
};





//*******************IMPROVED SOLUTION********************



/*
//DOUBT
why can't we use set instead of unordered_set,it will keep the data in sorted(ascending) order as well as won't store duplicates??so that way we won't be needing min_heap and unordered_set,only set will be sufficient????
//DOUBT SOLVED IN OPTIMAL SOLUTION
*/





//data structure min_heap implemented using priority queue,minimum heap ke sabse top ka element sabse minimum hota hai.

//priority queue is internally an implementation of min heap or max heap
//priority queue gives the minimum/maximum element which is the topmost element in O(1)/or constant time complexity even though the elements present are in millions or trillions.
//priority queue is a container adaptor,that means it's not a container but adapting a conatiner which is vector,priority queue provides constant time lookup of the largest or smallest element.Cost of insertion and Extraction is logarithmic,by default vector is the container used inside(vector is kind of dynamic array),this array gets converted into heap.
//priority queue is implemented using make_heap,push_heap,pop_heap functions.
//https://youtu.be/JSqznrzWGvc







/*
//PRIORITY QUEUE TOP() FUNCTION----->

//syntax:
//pqueuename.top()

//Parameters :
//No value is needed to pass as the parameter.

//Returns :
//Direct reference to the top element of the priority queue container.

*/


/*
//UNORDERED SET ERASE() FUNCTION----->

//syntax:
//1. setname.erase(position)
//2. setname.erase(startingposition, endingposition)

//Parameters :
//Position of the element to be removed in the form of iterator or the range specified using start and end iterator.

//Result :
//Elements are removed from the specified position of the container.


*/



#include <queue>
#include<unordered_set>


class SmallestInfiniteSet 
{
  public:
  int currentSmallest;
  unordered_set <int> us;
  priority_queue <int,vector <int>,greater<int>> pq;
    SmallestInfiniteSet() 
    {
        currentSmallest=1;
    }
    
    int popSmallest() 
    {
        int result;
        if(!pq.empty())
        {
            result=pq.top(); //sabse chota element priority queue ke top par hoga kyonki min heap hai.
            pq.pop();
            us.erase(result); //result variable was storing direct reference to the top element of the priority queue container.
            //And erase() function of unordered_set takes an iterator as parameter.
            //what is iterator actually???
            //Iterators are used to point at the memory addresses of STL containers.
            //https://www.geeksforgeeks.org/iterators-c-stl/
        }
        else
        {
            result=currentSmallest;
            currentSmallest +=1;
        }


        return result;
        
    }
    
    void addBack(int num) 
    {
        if(num>=currentSmallest || us.find(num)!=us.end()) return;
        else
        {
            us.insert(num);
            pq.push(num);
        }
    }
};



//*****************OPTIMAL /BEST APPROACH*****************************
//USING ORDERED SET

#include<set>

class SmallestInfiniteSet 
{
    int currsmallest;
    set <int> st;
  public:
    SmallestInfiniteSet() 
    {
        currsmallest=1;
    }
    
    int popSmallest() 
    {
        int result;
        if(!st.empty())
        {
            result=*st.begin();
            st.erase(st.begin());
        }
        else
        {
            result=currsmallest;
            currsmallest +=1;
        }
        return result;
    }
    
    void addBack(int num) 
    {
        if(num>=currsmallest || st.find(num)!=st.end()) return;
        else
        {
            st.insert(num);
        }
    }
};




int main()
{
    SmallestInfiniteSet obj;
    int output;
    //["SmallestInfiniteSet","addBack","popSmallest","popSmallest","popSmallest","addBack","popSmallest","popSmallest","popSmallest"]
    //[[],[2],[],[],[],[1],[],[],[]]
    obj.addBack(2);
    output=obj.popSmallest();  cout<<output<<" ";
    output=obj.popSmallest();  cout<<output<<" ";
    output=obj.popSmallest();  cout<<output<<" ";
    obj.addBack(1);
    output=obj.popSmallest();  cout<<output<<" ";
    output=obj.popSmallest();  cout<<output<<" ";
    output=obj.popSmallest();  cout<<output<<" ";

    //EXPECTED OUTPUT: [null,null,1,2,3,null,1,4,5]
    return 0;
}