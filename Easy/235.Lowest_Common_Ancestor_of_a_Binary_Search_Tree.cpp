/*
  Problem Link    :
  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//  Recursive DFS
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (!left)
            return right;
        else if (!right)
            return left;
        else
            return root;
    }
};

//  DFS recursive
//  Time Complexity - O(n)
//  Space Complexity - O(h)
class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return root;
        }
    }
};

//  Iterative
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root)
            if (p->val > root->val && q->val > root->val)
                root = root->right;
            else if (p->val < root->val && q->val < root->val)
                root = root->left;
            else
                return root;

        return NULL;
    }
};