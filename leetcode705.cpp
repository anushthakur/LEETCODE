//705. Design HashSet


#include<list>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


//FRAZ
class MyHashSet 
{
 public:
 vector<list<int>> vl;
 int size;

    MyHashSet() 
    {
        size=1000;
        vl.resize(size);
       
    }

    int hashfunction(int key)
    {
        return key%size;
    }

    list <int> :: iterator searchfunction(int key)
    {
        int i=hashfunction(key);
        return find(vl[i].begin(),vl[i].end(),key);
    }
    
    void add(int key)
    {
        if(contains(key)) return;
        int i=hashfunction(key);
        vl[i].push_back(key);
    }
    
    void remove(int key) 
    {
        if(!contains(key)) return;
        int i=hashfunction(key);
        vl[i].erase(searchfunction(key));
    }
    
    bool contains(int key) 
    {
        int i=hashfunction(key);
        if(searchfunction(key) != vl[i].end()) return true;
        else return false;
        
    }
};


/*
class MyHashSet 
{
 public:
 vector <int> v;
 int size;

    MyHashSet() 
    {
        size=1e6 + 1;    //1*10 to the power 6
        v.resize(size);
       
    }
    
    void add(int key)
    {
        v[key]=1;
    }
    
    void remove(int key) 
    {
        v[key]=0;
    }
    
    bool contains(int key) 
    {
        return v[key];
    }
};
*/

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */