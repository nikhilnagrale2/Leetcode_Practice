/*
  Problem Link    :   https://leetcode.com/problems/delete-node-in-a-bst/

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

//  Recursive Solution
//  Time Complexity - O(h)
//  Space Complexity - O(1)
class Solution {
   public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root)
            return root;
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left && !root->right) {
                delete root;
                root = NULL;
            } else if (!root->left) {
                TreeNode *temp = root;
                root = root->right;
                delete temp;
            } else if (!root->right) {
                TreeNode *temp = root;
                root = root->left;
                delete temp;
            } else {
                TreeNode *temp = findMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }

   private:
    TreeNode *findMin(TreeNode *root) {
        while (root->left) root = root->left;
        return root;
    }
};