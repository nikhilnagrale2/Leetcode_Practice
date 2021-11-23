/*
  Problem Link    :
  https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

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

//  Solution Using stoull and String
//  Time Complexity - O(n)
//  Space Complexity - O(n)
/*
    Traverse the linked list and convert it into a string.
    Convert the string into an integer using stoull.
*/
class Solution {
   public:
    int getDecimalValue(ListNode *head) {
        int ans = 0;
        string s;
        while (head) {
            s += to_string(head->val);
            head = head->next;
        }
        ans = (int)stoull(s, 0, 2);
        return ans;
    }
};

//  Bit Operation Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)
/*
    Traverse the linked list and convert it into an integer by left shifting the
   integer by 1. Bit OR the integer with the value of the current node.
*/
class Solution {
   public:
    int getDecimalValue(ListNode *head) {
        int ans = 0;
        while (head) {
            ans <<= 1;
            ans |= head->val;
            head = head->next;
        }
        return ans;
    }
};

// * stoull function is op
