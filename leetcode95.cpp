//95. Unique Binary Search Trees II

#include<bits/stdc++.h>
using namespace std;


 //Definition for a binary tree node.
  struct TreeNode 
  {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

 //codestorywithMIK
class Solution 
{
public:
//concept: In binary search tree its each subtree is a binary search tree itself.
//total number of BST's possible= 4^n/n^(1.5) : catalar number
//TIME COMPLEXITY:O(n*(catalar no.))

   // unordered_map <pair<int,int>,vector<TreeNode*>> mp; //error????
   map <pair<int,int>,vector<TreeNode*>> mp;

    vector<TreeNode*> solve(int start,int end)
    {
        if(start>end) return {NULL};

        if(start==end) 
        {
            TreeNode* root=new TreeNode(start);
            return mp[{start,end}]={root};
        }
        if(mp.find({start,end})!=mp.end())
        {
            return mp[{start,end}];
        }

        vector<TreeNode*> ans;
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> left_BST=solve(start,i-1);
            vector<TreeNode*> right_BST=solve(i+1,end);

            for(TreeNode* x:left_BST)
            {
                for(TreeNode* y:right_BST)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=x;
                    root->right=y;

                    ans.push_back(root);
                }
            }

        }
        return mp[{start,end}]=ans;
    }
    vector<TreeNode*> generateTrees(int n) 
    {
        return solve(1,n);
    }
};