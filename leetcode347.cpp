//347. Top K Frequent Elements

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//CORRECT
//Time complexity: O(n log k) ??check and O(n^2) in worst case
//Space complexity: O(n)

class Solution 
{
 public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector <int> ans;
        unordered_map <int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        priority_queue <pair<int,int>> pq;

        for(const auto & x: mp)
        {
            pq.push({x.second,x.first});
        }

        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

//OPTIMAL SOLUTION
//TIME COMPLEXITY:O(n) + O(n) + O(k)
//SPACE COMPLEXITY:O(n) + O(n^2) (for 2D vector in worst case)

//https://youtu.be/xZTy81rEsyg


class Solution 
{
 public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector <int> ans;
        if(!nums.size()) return ans;
        unordered_map <int,int> mp;
        for(const auto & x: nums)
        {
            mp[x]++;
        }

        vector<vector<int>> bucket(nums.size()+1);

        for(const auto & x: mp)
        {
            bucket[x.second].push_back(x.first); //learn this syntax
        }

        for( int i=bucket.size()-1;i>=0;i--)
        {
            for(int j=0;j<bucket[i].size();j++) //O(k) and not O(n^2)
            {
                ans.push_back(bucket[i][j]);
                if(ans.size()==k) return ans;
            }
        }
        return ans;
    }
};



//TRIAL (made a new ques. out of it....I solved for elements who are frequent at least k times)
//but the ques. asks different,we need to find k elements which are most frequent.

#include<unordered_set>
#include<unordered_map>

class Solution 
{
 public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector <int> ans;
        unordered_set <int> st;
        unordered_map <int,int> mp;
        for(const auto & x: nums)
        {
            mp[x]++;
            if(mp[x] >=k) st.insert(x);
            
        }
        for(const auto & x:st)
        {
            ans.push_back(x);
        }
        return ans;
    }
};

/*
//https://chat.openai.com/

The time complexity of this code is O(n), where n is the number of elements in the input vector nums.

The space complexity of this code is O(m), where m is the number of distinct elements in the input vector nums.

Let's analyze the space complexity:

The code uses a vector ans to store the result, which can have at most k elements. Hence, the space complexity for the vector ans is O(k).

The code uses an unordered set st to store the k most frequent elements. The number of elements in st can be at most k. Hence, the space complexity for the unordered set st is O(k).

The code uses an unordered map mp to store the frequencies of each element in nums. The size of mp can be at most the number of distinct elements in nums, denoted by m. Hence, the space complexity for the unordered map mp is O(m).

Therefore, the total space complexity of the code is O(k + m).

To summarize:

Time complexity: O(n)
Space complexity: O(k + m)



*/