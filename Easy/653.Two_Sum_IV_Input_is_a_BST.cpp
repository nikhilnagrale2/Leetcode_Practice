/*
  Problem Link    :   https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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

//  BFS Level Order Using Queue and set
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    bool findTarget(TreeNode *root, int k) {
        set<int> st;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode *curr = q.front();
                q.pop();
                if (st.find(k - curr->val) != st.end())
                    return true;
                else
                    st.insert(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return false;
    }
};

//  Inorder DFS Recursive by creating Vector
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    void inorder(TreeNode *root, vector<int> &nums) {
        if (!root) return;
        if (root->left) inorder(root->left, nums);
        nums.push_back(root->val);
        if (root->right) inorder(root->right, nums);
    }

    bool findTarget(TreeNode *root, int k) {
        vector<int> nums;
        inorder(root, nums);
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (k == sum)
                return true;
            else if (k < sum)
                right--;
            else
                left++;
        }
        return false;
    }
};

//  * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/discuss/106063/C%2B%2B-Clean-Code-O(n)-time-O(lg-n)-space-BinaryTree-Iterator
//  * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/discuss/106059/JavaC++-Three-simple-methods-choose-one-you-like/139201
//  BST Iterator Using Stack
//  Time Complexity - O(n)
//  Space Complexity - O(logn) on average - O(n) worst case
class Solution {
   public:
    bool findTarget(TreeNode *root, int k) {
        stack<TreeNode *> leftstack;
        stack<TreeNode *> rightstack;
        TreeNode *temp = root;
        while (temp) {
            leftstack.push(temp);
            temp = temp->left;
        }
        temp = root;
        while (temp) {
            rightstack.push(temp);
            temp = temp->right;
        }
        while (!leftstack.empty() && !rightstack.empty() &&
               leftstack.top() != rightstack.top()) {
            // top is checked to not to use duplicate values
            TreeNode *lefttop = leftstack.top();
            TreeNode *righttop = rightstack.top();
            int sum = lefttop->val + righttop->val;
            if (sum == k) {
                return true;
            } else if (sum < k) {
                temp = leftstack.top()->right;
                leftstack.pop();
                while (temp != NULL) {
                    leftstack.push(temp);
                    temp = temp->left;
                }
            } else {
                temp = rightstack.top()->left;
                rightstack.pop();
                while (temp != NULL) {
                    rightstack.push(temp);
                    temp = temp->right;
                }
            }
        }

        return false;
    }
};

//  DFS Recursive
//  Time Complexity - O(nh)
//  Space Complexity - O(h)
class Solution {
   public:
    TreeNode *root;
    bool search(TreeNode *node, int k) {
        TreeNode *curr = root;
        while (curr) {
            if (k > curr->val)
                curr = curr->right;
            else if (k < curr->val)
                curr = curr->left;
            else
                return curr != node ? true : false;
        }
        return false;
    }

    bool findTarget(TreeNode *node, int k) {
        if (!root) root = node;
        if (!node) return false;
        if (search(node, k - node->val)) return true;
        return findTarget(node->left, k) || findTarget(node->right, k);
    }
};