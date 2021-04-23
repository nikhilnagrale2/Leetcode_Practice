/*
  Problem Link    :   https://leetcode.com/problems/reorder-list/

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

//  Iterative Version
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    ListNode *cutInHalf(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *reverse(ListNode *head) {
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

    void reorderList(ListNode *head) {
        ListNode *rev = cutInHalf(head);
        rev = reverse(rev);
        ListNode *n1 = head, *n2 = rev;
        while (n2->next) {
            ListNode *temp = n1->next;
            n1->next = n2;
            n1 = temp;

            temp = n2->next;
            n2->next = n1;
            n2 = temp;
        }
    }
};

