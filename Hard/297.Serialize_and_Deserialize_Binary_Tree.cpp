/*
  Problem Link    :
  https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

//  DFS Recursive
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return (!root) ? " #"
                       : " " + to_string(root->val) + serialize(root->left) +
                             serialize(root->right);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream s(data);
        return buildTree(s);
    }

   private:
    TreeNode* buildTree(istringstream& str) {
        string s;
        str >> s;
        if (s == "#") return NULL;
        TreeNode* node = new TreeNode(stoi(s));
        node->left = buildTree(str);
        node->right = buildTree(str);
        return node;
    }
};

//  DFS Recursive
//  serialize function in iterative
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        stack<TreeNode*> stk;
        if (!root) return " #";
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* curr = stk.top();
            stk.pop();
            data += curr ? " " + to_string(curr->val) : " #";
            if (curr) {
                stk.push(curr->right);
                stk.push(curr->left);
            }
        }
        return data;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream s(data);
        return buildTree(s);
    }

   private:
    TreeNode* buildTree(istringstream& str) {
        string s;
        str >> s;
        if (s == "#") return NULL;
        TreeNode* node = new TreeNode(stoi(s));
        node->left = buildTree(str);
        node->right = buildTree(str);
        return node;
    }
};
