/*
  Problem Link    :   https://leetcode.com/problems/validate-binary-search-tree/

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

//  Recursive DFS
//  Time Complexity - O(nodes)
//  Space Complexity - O(nodes)
class Solution {
   public:
    bool check(TreeNode* root, long left, long right) {
        if (!root) return true;
        int value = root->val;
        return value > left && value < right &&
               check(root->left, left, value) &&
               check(root->right, value, right);
    }

    bool isValidBST(TreeNode* root) { return check(root, LONG_MIN, LONG_MAX); }
};

//  Iterative Inorder DFS
//  Time Complexity - O(nodes)
//  Space Complexity - O(nodes)
class Solution {
   public:
    bool isValidBST(TreeNode* root) {
        long pre = LONG_MIN;
        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->val <= pre) return false;
            pre = root->val;
            root = root->right;
        }
        return true;
    }
};

//  Without inf value
// * https://leetcode.com/problems/validate-binary-search-tree/discuss/32104/C%2B%2B-in-order-traversal-and-please-do-not-rely-on-buggy-INT_MAX-INT_MIN-solutions-any-more