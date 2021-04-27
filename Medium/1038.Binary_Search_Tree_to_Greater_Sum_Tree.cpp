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

//  DFS ReverseInorder Recursive
//  Time Complexity - O(n)
//  Space Complexity- O(n)
class Solution {
   public:
    int reverseInorder(TreeNode* root, int sum) {
        if (!root) return sum;
        sum = reverseInorder(root->right, sum);
        root->val += sum;
        sum = root->val;
        return reverseInorder(root->left, sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        reverseInorder(root, 0);
        return root;
    }
};

//  DFS ReverseInorder Iterative
//  Time Complexity - O(n)
//  Space Complexity- O(n)
class Solution {
   public:
    TreeNode* bstToGst(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        int sum = 0;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->right;
            }
            curr = stk.top();
            stk.pop();
            sum += curr->val;
            curr->val = sum;
            curr = curr->left;
        }
        return root;
    }
};

//  Morris ReverseInorder Traversal
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    TreeNode* bstToGst(TreeNode* root) {
        TreeNode* curr = root;
        int sum = 0;
        while (curr) {
            if (curr->right) {
                TreeNode* predecessor = curr->right;
                while (predecessor->left != curr && predecessor->left != NULL) {
                    predecessor = predecessor->left;
                }
                if (predecessor->left) {
                    predecessor->left = NULL;
                    sum += curr->val;
                    curr->val = sum;
                    curr = curr->left;
                } else {
                    predecessor->left = curr;
                    curr = curr->right;
                }
            } else {
                sum += curr->val;
                curr->val = sum;
                curr = curr->left;
            }
        }
        return root;
    }
};