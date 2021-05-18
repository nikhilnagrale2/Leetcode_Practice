/*
  Problem Link    :
  https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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

//  BFS
//  Time Complexity - O(node)
//  Space Complexity - O(node)
class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> curr(sz);
            for (int i = 0; i < sz; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                if (level == 0)
                    curr[i] = tmp->val;
                else
                    curr[sz - i - 1] = tmp->val;

                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            ans.push_back(curr);
            level = !level;
        }
        return ans;
    }
};