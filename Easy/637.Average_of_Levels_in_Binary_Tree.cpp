/*
  Problem Link    :   https://leetcode.com/problems/average-of-levels-in-binary-tree

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//  Solution Using BFS
//  Time Complexity - O(n)
//  Space Complexity - O(m) - m refers to max number of nodes at any level in binary tree

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            double sum = 0;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                sum += node->val;
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
                q.pop();
            }
            ans.push_back(sum / size);
        }
        return ans;
    }
};

//  Solution Using DFS
//  Time Complexity - O(n)
//  Space Complexity - O(h) -- height
class Solution
{
public:
    void average(TreeNode *root, vector<int> &count, vector<double> &ans, int level)
    {
        if (!root)
            return;

        if (count.size() <= level)
        {
            count.push_back({});
        }
        if (ans.size() <= level)
        {
            ans.push_back({});
        }

        count[level]++;
        ans[level] += root->val;

        average(root->left, count, ans, level + 1);
        average(root->right, count, ans, level + 1);
    }

    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;
        vector<int> count;
        average(root, count, ans, 0);
        for (int i = 0; i < ans.size(); i++)
        {
            ans[i] /= count[i];
        }
        return ans;
    }
};