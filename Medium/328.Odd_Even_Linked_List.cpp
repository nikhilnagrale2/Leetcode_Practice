/*
  Problem Link    :

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

//  Bruteforce
//  Time Complexity - O(nodes)
//  Space Complexity - O(nodes)
class Solution {
   public:
    ListNode *oddEvenList(ListNode *head) {
        ListNode *res = new ListNode(0);
        if (head == NULL) return res->next;
        ListNode *temp = res;
        ListNode *head2 = head->next;
        while (head) {
            temp->next = new ListNode(head->val);
            temp = temp->next;
            if (head->next && head->next->next)
                head = head->next->next;
            else
                break;
        }
        while (head2) {
            temp->next = new ListNode(head2->val);
            temp = temp->next;
            if (head2->next && head2->next->next)
                head2 = head2->next->next;
            else
                break;
        }
        return res->next;
    }
};

//  Optimal Solution
//  Time Complexity - O(nodes)
//  Space Complexity - O(1)
class Solution {
   public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head) return NULL;
        ListNode *odd = head, *even = head->next, *evenHead = even;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};