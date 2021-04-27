/*
  Problem Link    :   https://leetcode.com/problems/same-tree/s

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

//  Recursive
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left)
    }
};

//  Iterative DFS with stack
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> stk;
        stk.push({p, q});
        while (!stk.empty()) {
            TreeNode* node1 = stk.top().first;
            TreeNode* node2 = stk.top().second;
            stk.pop();
            if (!node1 && !node2)
                continue;
            else if (!node1 || !node2)
                return false;
            else {
                if (node1->val != node2->val) return false;
                stk.push({node1->left, node2->left});
                stk.push({node1->right, node2->right});
            }
        }
        return true;
    }
};

//  Iterative BFS with queue
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> que;
        que.push({p, q});
        while (!que.empty()) {
            TreeNode* node1 = que.front().first;
            TreeNode* node2 = que.front().second;
            que.pop();
            if (!node1 && !node2)
                continue;
            else if (!node1 || !node2)
                return false;
            else {
                if (node1->val != node2->val) return false;
                que.push({node1->left, node2->left});
                que.push({node1->right, node2->right});
            }
        }
        return true;
    }
};