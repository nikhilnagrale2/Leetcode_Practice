/*
  Problem Link    :   https://leetcode.com/problems/add-two-numbers-ii/

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

//  By Reversing LinkedList
//  Time Complexity - O(n+m)
//  Space Complexity - O(n+m)
class Solution {
   public:
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

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode *head = new ListNode();
        ListNode *curr = head;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            curr->next = node;
            curr = curr->next;
        }
        return reverse(head->next);
    }
};

//  Most Appropriate Solution
//  Time Complexity - O(n+m)
//  Space Complexity - O(n+m)
class Solution {
   public:
    int size(ListNode *head) {
        int size = 0;
        while (head) {
            size++;
            head = head->next;
        }
        return size;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int s1 = size(l1), s2 = size(l2);
        ListNode *resHead = NULL;
        ListNode *n = NULL;

        while (l1 || l2) {
            int v1 = 0, v2 = 0;
            if (s1 >= s2) {
                v1 = l1 ? l1->val : 0;
                l1 = l1->next;
                s1--;
            }
            if (s2 >= s1 + 1) {
                v2 = l2 ? l2->val : 0;
                l2 = l2->next;
                s2--;
            }
            n = new ListNode(v1 + v2);
            n->next = resHead;
            resHead = n;
        }
        int carry = 0;
        resHead = NULL;
        while (n) {
            n->val += carry;
            if (n->val >= 10) {
                n->val = n->val % 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ListNode *buf = n->next;
            n->next = resHead;
            resHead = n;
            n = buf;
        }
        if (carry > 0) {
            n = new ListNode(1);
            n->next = resHead;
            resHead = n;
        }
        return resHead;
    }
};