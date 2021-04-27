/*
  Problem Link    : https://leetcode.com/problems/binary-tree-maximum-path-sum/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  DFS Recursive
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    int dfs(TreeNode *root, int &maxPSum) {
        if (!root) return 0;
        int left = max(0, dfs(root->left, maxPSum));
        int right = max(0, dfs(root->right, maxPSum));
        maxPSum = max(maxPSum, left + right + root->val);
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode *root) {
        int maxPSum = INT_MIN;
        dfs(root, maxPSum);
        return maxPSum;
    }
};

//  DFS Iterative with
//  Time Complexity - O(n)
//  Space Complexity - O(n)

//  TODO:https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/39802/Iterative-solution-using-Stack.