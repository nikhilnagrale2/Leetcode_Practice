/*
  Problem Link    : https://leetcode.com/problems/merge-in-between-linked-lists/

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

//  Time Complexity - O(n+m)
//  Space Complexity - O(1)
class Solution {
   public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int diff = b - a;
        a--;
        ListNode* l1 = list1;
        while (a--) l1 = l1->next;
        ListNode* temp = l1->next;
        while (diff--) temp = temp->next;
        l1->next = list2;
        while (l1->next) l1 = l1->next;
        l1->next = temp->next;
        return list1;
    }
};