/*
  Problem Link    :   https://leetcode.com/problems/linked-list-cycle-ii/

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

//  Set Solution
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode *> st;
        while (head) {
            if (st.find(head) != st.end()) return head;
            st.insert(head);
            head = head->next;
        }
        return NULL;
    }
};

//  Two Pointer
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
        ListNode *slow = head, *fast = head, *entry = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                while (entry != slow) {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};