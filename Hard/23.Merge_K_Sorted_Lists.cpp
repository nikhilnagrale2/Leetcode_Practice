/*
  Problem Link    :   https://leetcode.com/problems/merge-k-sorted-lists/

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

//  Brute
//  Time Complexity - O(nlogn)
//  Space Complexity - O(n)
class Solution {
   public:
    vector<int> ans;
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        for (auto x : lists) {
            while (x) {
                ans.push_back(x->val);
                // cout<<x->val<<" ";
                x = x->next;
            }
        }
        sort(ans.begin(), ans.end());
        return createLinkedList();
    }

   private:
    ListNode *createLinkedList() {
        ListNode *root = new ListNode(0);
        ListNode *node = root;
        for (int i = 0; i < ans.size(); i++) {
            ListNode *temp = new ListNode(ans[i]);
            node->next = temp;
            node = node->next;
        }
        return root->next;
    }
};

//  Merge K Lists
//  Time Complexity - O(nk)
//  Space Complexity - O(1)
class Solution {
   public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *result = NULL;
        for (auto x : lists) {
            result = mergeTwoLists(result, x);
        }
        return result;
    }

   private:
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

//  Priority Queue
//  Time Complexity - O(nlogk)
//  Space Complexity - O(n)
class Solution {
   public:
    struct compare {
        bool operator()(const ListNode *l, const ListNode *r) {
            return l->val > r->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *root = new ListNode(0);
        ListNode *node = root;
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;
        for (auto x : lists)
            if (x) pq.push(x);
        while (pq.size() != 0) {
            ListNode *temp = pq.top();
            pq.pop();
            node->next = new ListNode(temp->val);
            node = node->next;
            temp = temp->next;
            if (temp) pq.push(temp);
        }
        return root->next;
    }
};

// TODO: Merge with Divide And Conquer