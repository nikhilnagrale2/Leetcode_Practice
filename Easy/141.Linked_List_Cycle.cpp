/*
  Problem Link    :   https://leetcode.com/problems/linked-list-cycle/

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

//  Hash Function Set Solution
//  Time Complexity - O(nlogn)
//  Space Complexity - O(n)
class Solution {
   public:
    bool hasCycle(ListNode *head) {
        set<ListNode *> st;
        while (head) {
            if (st.find(head) != st.end()) return true;
            st.insert(head);
            head = head->next;
        }
        return false;
    }
};

//  Hare and Tortoise Algorithm
//  Two Pointer
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};