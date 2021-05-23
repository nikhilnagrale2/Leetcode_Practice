/*
  Problem Link    : https://leetcode.com/problems/delete-node-in-a-linked-list/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//   Mind Boggler
class Solution {
   public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete curr;
    }
};

//  One liner
class Solution {
   public:
    void deleteNode(ListNode* node) { *node = *node->next; }
};