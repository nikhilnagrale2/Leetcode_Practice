/*
  Problem Link    :   https://leetcode.com/problems/merge-two-sorted-lists/

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

//  Naive Solution  - 4ms
//  Time Complexity - O(n+m)
//  Space Complexity - O(n+m)
class Solution {
   public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode(0);
        ListNode *head = res;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                head->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                head->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            head = head->next;
        }

        while (l1) {
            head->next = new ListNode(l1->val);
            l1 = l1->next;
            head = head->next;
        }
        while (l2) {
            head->next = new ListNode(l2->val);
            l2 = l2->next;
            head = head->next;
        }

        return res->next;
    }
};

//  Iterative Solution In-Place - 12ms
//  Time Complexity - O(n+m)
//  Space Complexity - O(1)
class Solution {
   public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val > l2->val) swap(l1, l2);
        ListNode *head = l1;
        while (l1 && l2) {
            ListNode *curr = NULL;
            while (l1 && l1->val <= l2->val) {
                curr = l1;
                l1 = l1->next;
            }
            curr->next = l2;
            swap(l1, l2);
        }
        return head;
    }
};

//  8ms
//  Time Complexity - O(n+m)
class Solution {
   public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode(0);
        ListNode *head = res;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }

        if (l1 == NULL)
            head->next = l2;
        else
            head->next = l1;

        return res->next;
    }
};

//  Recursive Solution
//  Time Complexity - O(n+m)
class Solution {
   public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};