/*
  Problem Link    :
  https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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

//  Recursion
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    int preorderIndex = 0;
    map<int, int> inorderIndexMap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        }
        return arrayToTree(preorder, 0, preorder.size() - 1);
    }

   private:
    TreeNode* arrayToTree(vector<int> preorder, int left, int right) {
        if (left > right) return NULL;
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);
        root->left =
            arrayToTree(preorder, left, inorderIndexMap[rootValue] - 1);
        root->right =
            arrayToTree(preorder, inorderIndexMap[rootValue] + 1, right);
        return root;
    }
};

//  !https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/876673
//  Recursion without hashmap
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return helper(pre, in, 0, pre.size() - 1, 0, in.size() - 1);
    }

   private:
    TreeNode* helper(vector<int>& pre, vector<int>& in, int ps, int pe, int is,
                     int ie) {
        if (is > ie) return NULL;
        TreeNode* root = new TreeNode(pre[ps]);
        int pos;
        for (int i = is; i < ie; i++)
            if (in[i] == root->val) {
                pos = i;
                break;
            }
        // pe-ps = ie-is ==>> pe = ps+ie-is
        // now all should correspond to left part
        // pe = (ps+1)+(pos-1)-(is) = ps+pos-is
        root->left = helper(pre, in, ps + 1, ps + pos - is, is, pos - 1);
        root->right = helper(pre, in, ps + pos - is + 1, pe, pos + 1, ie);
        return root;
    }
};

//  !https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34543/Simple-O(n)-without-map/383711
//  Recursion without hashmap
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inPos = 0;
        int prePos = 0;
        return build(preorder, inorder, INT_MIN, inPos, prePos);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int stop,
                    int& inPos, int& prePos) {
        if (prePos >= preorder.size()) return NULL;
        if (inorder[inPos] == stop) {
            inPos++;
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[prePos++]);
        node->left = build(preorder, inorder, node->val, inPos, prePos);
        node->right = build(preorder, inorder, stop, inPos, prePos);
        return node;
    }
};