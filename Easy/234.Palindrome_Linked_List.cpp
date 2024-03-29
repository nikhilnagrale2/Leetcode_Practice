/*
  Problem Link    :   https://leetcode.com/problems/palindrome-linked-list/

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

//  Bruteforce Solution
//  Time Complexity - O(n)+O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    bool isPalindrome(vector<int> &p) {
        bool isP = true;
        for (int i = 0; i < p.size() / 2; i++)
            if (p[i] != p[p.size() - i - 1]) isP = false;
        return isP;
    }

    bool isPalindrome(ListNode *head) {
        vector<int> p;
        while (head) {
            p.push_back(head->val);
            head = head->next;
        }
        return isPalindrome(p);
    }
};

//  Recursive  -->
//  https://leetcode.com/problems/palindrome-linked-list/discuss/181453/Java-or-5-lines-method-or-2ms-or-O(n)-or-recursive-or-easy-to-understand

//  Time Complexity - O(n)
//  Space Complexity -  O(1) space
class Solution {
   public:
    ListNode *reverse(ListNode *head) {
        ListNode *prev = NULL, *curr = head;
        while (curr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode *middle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode *head) {
        ListNode *mid = middle(head);
        mid->next = reverse(mid->next);
        mid = mid->next;
        while (mid) {
            if (head->val != mid->val) return false;
            head = head->next;
            mid = mid->next;
        }
        return true;
    }
};