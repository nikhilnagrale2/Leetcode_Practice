/*
  Problem Link    :   https://leetcode.com/problems/reverse-linked-list/

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

//  Iterative Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

//  Recursive Solution
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    ListNode *reverse(ListNode *head, ListNode *newHead) {
        if (!head) return newHead;

        ListNode *next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;

        return reverse(head, newHead);
    }

    ListNode *reverseList(ListNode *head) { return reverse(head, NULL); }
};