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
//  Time Complexity - O(n*m)
//  Space Complexity - O(n)
class Solution {
   public:
    bool isEqual(TreeNode* s, TreeNode* t) {
        if (!s || !t) return s == t;
        if (s->val != t->val) return false;
        return isEqual(s->left, t->left) && isEqual(s->right, t->right);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        return isEqual(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};

//  Serialization
//  Time Complexity - O(m+n+m*n)
//  Space Complexity - O(m+n)
class Solution {
   public:
    void serialize(TreeNode* root, string& res) {
        if (!root) {
            res += '#null';
            return;
        }
        res += "#" + to_string(root->val);
        serialize(root->left, res);
        serialize(root->right, res);
    }

    string serialize(TreeNode* root) {
        string res;
        serialize(root, res);
        return res;
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        string ss = serialize(s), tt = serialize(t);
        cout << ss << endl << tt << endl;
        if (ss.find(tt) != string::npos) return true;
        return false;
    }
};