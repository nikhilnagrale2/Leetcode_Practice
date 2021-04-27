/*
  Problem Link    :   https://leetcode.com/problems/invert-binary-tree/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

//  DFS Recursive
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* temp = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(temp);
        return root;
    }
};

//  DFS Iterative
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* curr = stk.top();
            stk.pop();
            swap(curr->right, curr->left);
            if (curr->left) stk.push(curr->left);
            if (curr->right) stk.push(curr->right);
        }
        return root;
    }
};

//  BFS Level Order Iterative with queue
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            swap(curr->right, curr->left);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        return root;
    }
};