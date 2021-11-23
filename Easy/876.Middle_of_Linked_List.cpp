/*
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

//  Bruteforce Array
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> list;
        while (head) {
            list.push_back(head);
            head = head->next;
        }
        return list[list.size() / 2];
    }
};

//  Two Traversal
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    ListNode* middleNode(ListNode* head) {
        ListNode* node = head;
        int n = 0;
        while (node) {
            n++;
            node = node->next;
        }
        node = head;
        n = n / 2;
        while (n--) {
            node = node->next;
        }
        return node;
    }
};

//  Hare and Tortoise Algorithm
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    ListNode* middleNode(ListNode* head) {
        if (!head->next) return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = slow->next;
        return slow;
    }
};

class Solution {
   public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};