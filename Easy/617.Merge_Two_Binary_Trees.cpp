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

//  DFS Solution
//  Time Complexity - O(nodes)
//  Space Complexity - O(nodes) - Implicit stack
class Solution {
   public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        return new TreeNode(root1->val + root2->val,
                            mergeTrees(root1->left, root2->left),
                            mergeTrees(root1->right, root2->right));
    }
};

//  BFS Level Order Iterative
//  Time Complexity - O(nodes)
//  Space Complexity - O(nodes)
class Solution {
   public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return NULL;
        if (!root1 || !root2) return root1 ? root1 : root2;

        queue<TreeNode*> q1, q2;
        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {
            TreeNode* curr1(q1.front());
            TreeNode* curr2(q2.front());
            q1.pop();
            q2.pop();

            curr1->val += curr2->val;

            if (!curr1->left && curr2->left)
                curr1->left = curr2->left;
            else if (curr1->left && curr2->left) {
                q1.push(curr1->left);
                q2.push(curr2->left);
            }

            if (!curr1->right && curr2->right)
                curr1->right = curr2->right;
            else if (curr1->right && curr2->right) {
                q1.push(curr1->right);
                q2.push(curr2->right);
            }
        }
        return root1;
    }
};