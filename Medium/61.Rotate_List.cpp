/*
  Problem Link    :   https://leetcode.com/problems/rotate-list/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Optimal Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* curr = head;
        int len = 1;
        while (curr->next && ++len) curr = curr->next;
        curr->next = head;
        k = len - k % len;
        while (k--) curr = curr->next;
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};