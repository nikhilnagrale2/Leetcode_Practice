/*
  Problem Link    :
  https://leetcode.com/problems/remove-duplicates-from-sorted-list/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive Solution Using Set
//  Time Complexity - O(nlogn)
//  Space Complexity - O(n)
class Solution {
   public:
    ListNode *deleteDuplicates(ListNode *head) {
        set<int> st;
        ListNode *res = new ListNode(0);
        ListNode *curr = res;
        while (head) {
            if (st.find(head->val) == st.end()) {
                ListNode *temp = new ListNode(head->val);
                curr->next = temp;
                curr = curr->next;
                st.insert(head->val);
            }
            head = head->next;
        }
        return res->next;
    }
};

//  Optimal Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *curr = head;
        while (curr && curr->next) {
            if (curr->next->val == curr->val) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};