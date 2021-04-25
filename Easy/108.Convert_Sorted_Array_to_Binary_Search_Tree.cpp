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

//  Recursive Similar to Binary Search
//  Time Complexity - O(nodes)
//  Space Complexity - O(nodes)
class Solution {
   public:
    TreeNode *helper(vector<int> &nums, int left, int right) {
        if (left <= right) {
            int mid = left + (right - left) / 2;
            TreeNode *node = new TreeNode(nums[mid]);
            node->left = helper(nums, left, mid - 1);
            node->right = helper(nums, mid + 1, right);
            return node;
        }
        return NULL;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};

//  Iterative DFS
//  Time Complexity - O(nodes)
//  Space Complexity - O(nodes)
struct object {
    TreeNode *root;
    int left;
    int right;
};

class Solution {
   public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        TreeNode *root = new TreeNode();
        stack<object> stk;
        int n = nums.size();
        stk.push({root, 0, n - 1});
        while (!stk.empty()) {
            TreeNode *node = stk.top().root;
            int left = stk.top().left, right = stk.top().right;
            stk.pop();
            int mid = left + (right - left) / 2;
            node->val = nums[mid];
            node->left = left < mid ? new TreeNode() : NULL;
            node->right = mid < right ? new TreeNode() : NULL;
            if (node->right) stk.push({node->right, mid + 1, right});
            if (node->left) stk.push({node->left, left, mid - 1});
        }
        return root;
    }
};

//  BFS Iterative
//  Time Complexity - O(nodes)
//  Space Complexity - O(nodes)
struct object {
    TreeNode *root;
    int left;
    int right;
};

class Solution {
   public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        TreeNode *root = new TreeNode();
        queue<object> q;
        int n = nums.size();
        q.push({root, 0, n - 1});
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode *node = q.front().root;
                int left = q.front().left, right = q.front().right;
                q.pop();
                int mid = left + (right - left) / 2;
                node->val = nums[mid];
                node->left = left < mid ? new TreeNode() : NULL;
                node->right = mid < right ? new TreeNode() : NULL;
                if (node->left) q.push({node->left, left, mid - 1});
                if (node->right) q.push({node->right, mid + 1, right});
            }
        }
        return root;
    }
};