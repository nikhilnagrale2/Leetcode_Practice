/*
  Problem Link    :   https://leetcode.com/problems/intersection-of-two-linked-lists/

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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//  Naive Solution
//  Time Complexity - O(n*m)
//  Space Complexity - O(1)
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        while (headA)
        {
            ListNode *temp = headB;
            while (temp)
            {
                if (headA == temp)
                {
                    return temp;
                }
                temp = temp->next;
            }
            headA = headA->next;
        }
        return NULL;
    }
};

//  HashMap Solution
//  Time Complexity - O(n+m)
//  Space Complexity - O(n)
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, int> mp;
        while (headA)
        {
            mp[headA]++;
            headA = headA->next;
        }
        while (headB)
        {
            if (mp[headB] > 0)
            {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};

//  Length Difference Solution
//  Time Complexity - O(n+m)
//  Space Complexity - O(1)

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lenA = 0, lenB = 0;
        ListNode *A = headA;
        ListNode *B = headB;
        while (A)
        {
            lenA++;
            A = A->next;
        }
        while (B)
        {
            lenB++;
            B = B->next;
        }
        int difference = abs(lenA - lenB);
        if (lenA > lenB)
        {
            while (difference)
            {
                headA = headA->next;
                difference--;
            }
        }
        else
        {
            while (difference)
            {
                headB = headB->next;
                difference--;
            }
        }
        while (headA && headB)
        {
            if (headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

//  Two Pointer Approach
//  Time Complexity - O(n+m)
//  Space Complexity - O(1)

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *A = headA;
        ListNode *B = headB;
        while (A != B)
        {
            if (A)
            {
                A = A->next;
            }
            else
            {
                A = headB;
            }
            if (B)
            {
                B = B->next;
            }
            else
            {
                B = headA;
            }
        }
        return A;
    }
};

// ----------------------------------------------------------------------
//  Different Cool Solutions to the Problem

//  Based on Floyd's Cycle Detection Algorithm
//  Hare and Tortoise Algorithm
//  Time Complexity - O()
//  Space Complexity - O(1)

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return NULL;

        ListNode *tail = headA;
        while (tail->next)
        {
            tail = tail->next;
        }
        tail->next = headA;

        ListNode *hare = headB;
        ListNode *tortoise = headB;

        if (!hare || !hare->next)
        {
            tail->next = NULL;
            return NULL;
        }

        while (hare && hare->next)
        {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (hare == tortoise)
                break;
        }

        if (hare != tortoise)
        {
            tail->next = NULL;
            return NULL;
        }

        tortoise = headB;

        while (tortoise != hare)
        {
            tortoise = tortoise->next;
            hare = hare->next;
        }

        tail->next = NULL;
        return tortoise;
    }
};

//  Using Hash Function - Set
//  Time Complexity - O(n+m)
//  Space Complexity - O(n or m)

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> st;
        while (headA)
        {
            st.insert(headA);
            headA = headA->next;
        }
        while (headB)
        {
            if (st.find(headB) != st.end())
            {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};