/*
  Problem Link    :
  https://leetcode.com/problems/search-in-a-binary-search-tree/

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
//  Time Complexity - O(h)
//  Space Complexity - O(h)
class Solution {
   public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL;
        if (root->val == val)
            return root;
        else if (root->val > val)
            return searchBST(root->left, val);
        return searchBST(root->right, val);
    }
};

//  Iterative
//  Time Complexity - O(h)
//  Space Complexity - O(1)
class Solution {
   public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root && root->val != val) {
            root = root->val > val ? root->left : root->right;
        }
        return root;
    }
};