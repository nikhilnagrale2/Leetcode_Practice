/*
  Problem Link    :   https://leetcode.com/problems/reverse-nodes-in-k-group/

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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//  Three Pointers
//  Time Complexity - O(k*(n/k))
//  Space Complexity - O(1)
class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy, *nex = dummy, *pre = dummy;
        int count = 0;
        while (cur->next) {
            count++;
            cur = cur->next;
        }
        while (count >= k) {
            cur = pre->next;
            nex = cur->next;
            for (int i = 1; i < k; i++) {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            count -= k;
            pre = cur;
        }
        return dummy->next;
    }
};