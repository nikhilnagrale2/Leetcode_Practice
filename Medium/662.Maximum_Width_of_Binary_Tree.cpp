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

//  DFS Recursive
//  Time Complexity - O(n)
//  Space Complexity - O(h) - implicit stack
class Solution {
   public:
    typedef unsigned long long ull;

    ull width(TreeNode *root, ull level, ull index,
              vector<pair<ull, ull>> &map) {
        if (!root) return 0;
        if (map.size() == level)
            map.push_back({index, index});
        else
            map[level].second = index;
        return max({map[level].second - map[level].first + 1,
                    width(root->left, level + 1, 2 * index + 1, map),
                    width(root->right, level + 1, 2 * index + 2, map)});
    }

    int widthOfBinaryTree(TreeNode *root) {
        return (int)width(root, 0, 0, vector<pair<ull, ull>>() = {});
    }
};

//  BFS Level Order Iterative
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    typedef unsigned long long ull;
    int widthOfBinaryTree(TreeNode *root) {
        if (!root) return 0;
        queue<pair<TreeNode *, ull>> q;
        q.push({root, 0});
        int width = 0;
        while (!q.empty()) {
            ull size = q.size();
            ull left = q.front().second, right = 0;
            while (size--) {
                pair<TreeNode *, ull> node = q.front();
                q.pop();
                right = node.second;
                if (node.first->left)
                    q.push({node.first->left, 2 * node.second + 1});
                if (node.first->right)
                    q.push({node.first->right, 2 * node.second + 2});
            }
            width = max(width, int(right - left + 1));
        }
        return width;
    }
};