/*
  Problem Link    :
  https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

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
//  Space Complexity- O(logn)
class Solution {
   public:
    int reversePreorder(TreeNode* root, int sum) {
        if (!root) return sum;
        sum = reversePreorder(root->right, sum);
        root->val += sum;
        sum = root->val;
        return reversePreorder(root->left, sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        reversePreorder(root, 0);
        return root;
    }
};