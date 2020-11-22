// Naive Solution Using Sort
// Time Complexity - O(nlogn)
// Space Complexity - O(n)
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        vector<int> a;
        for (int i = 0; i < A.size(); i++)
        {
            a.push_back(abs(A[i]));
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); i++)
            a[i] = a[i] * a[i];
        return a;
    }
};

// Solution Using Two Pointer
// Time Complexity - O(n)
// Space Complexity - O(n)
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        vector<int> ans(A.size());
        int start = 0;
        int end = A.size() - 1;

        for (int i = A.size() - 1; i >= 0; i--)
        {
            if (abs(A[start]) > abs(A[end]))
            {
                ans[i] = A[start] * A[start++];
            }
            else
            {
                ans[i] = A[end] * A[end--];
            }
        }
        return ans;
    }
};

//  Solution Using Doubly Ended Queue
//  Time Complexity - O(n)
//  Space Complexity - O()
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        deque<int> deq;

        for (auto x : A)
            deq.push_back(x);

        int i = A.size() - 1;
        while (!deq.empty())
        {
            int front = deq.front();
            int back = deq.back();

            if (abs(front) > abs(back))
            {
                deq.pop_front();
                A[i] = front * front;
            }
            else
            {
                deq.pop_back();
                A[i] = back * back;
            }
            i--;
        }

        return A;
    }
};

//Must Read
//https://leetcode.com/problems/squares-of-a-sorted-array/discuss/310865/Python%3A-A-comparison-of-lots-of-approaches!-Sorting-two-pointers-deque-iterator-generator