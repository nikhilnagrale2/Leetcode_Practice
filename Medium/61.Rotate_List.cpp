/*
  Problem Link    :   https://leetcode.com/problems/rotate-list/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Simple Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* curr = head;
        int count = 1;
        while (curr->next) {
            curr = curr->next;
            count++;
        }
        curr->next = head;
        k = count - k % count;
        while (k--) curr = curr->next;
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};