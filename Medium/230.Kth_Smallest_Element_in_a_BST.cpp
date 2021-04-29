/*
  Problem Link    : https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    int kthSmallest(TreeNode *root, int k) {
        vector<int> inorder;
        inorderT(root, inorder);
        return inorder[k - 1];
    }

   private:
    void inorderT(TreeNode *root, vector<int> &inorder) {
        if (!root) return;
        inorderT(root->left, inorder);
        inorder.push_back(root->val);
        inorderT(root->right, inorder);
    }
};

//  Recursive DFS
//  Time Complexity - O(n)
//  Space Complexity - O(h)
class Solution {
   public:
    int kthSmallest(TreeNode *root, int k) {
        int ans;
        inorderT(root, k, ans);
        return ans;
    }

   private:
    void inorderT(TreeNode *root, int &k, int &ans) {
        if (!root) return;
        inorderT(root->left, k, ans);
        if (--k == 0) ans = root->val;
        inorderT(root->right, k, ans);
    }
};

//  Iterative DFS
//  Time Complexity - O(n)
//  Space Complexity - O(h)
class Solution {
   public:
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> stk;
        while (true) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (--k == 0) return root->val;
            root = root->right;
        }
        return -1;
    }
};
