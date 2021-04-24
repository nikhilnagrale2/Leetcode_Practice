/*
  Problem Link    :

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

//  Naive Solution
//  Time Complexity - O(nodes*nodes)
//  Space Complexity - O(1)
class Solution {
   public:
    int height(TreeNode *root) {
        if (!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh, rh) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root) {
        if (!root) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);

        return max({ld, lh + rh, rd});
    }
};

//  Optimal Solution
//  Time Complexity - O(nodes)
//  Space Complexity - O(1)
class Solution {
   public:
    int height(TreeNode *root, int &diameter) {
        if (!root) return 0;

        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);

        diameter = max(diameter, lh + rh);

        return max(lh, rh) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root) {
        if (!root) return 0;

        int diameter = INT_MIN;
        height(root, diameter);
        return diameter;
    }
};