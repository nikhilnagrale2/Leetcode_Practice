/*
  Problem Link    : https://leetcode.com/problems/find-median-from-data-stream/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

//  Time Complexity - O(logn)
//  Space Complexity - O(logn)
class MedianFinder {
   public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

    void addNum(int num) {
        if (small.empty() || small.top() > num)
            small.push(num);
        else
            large.push(num);

        if (small.size() > large.size() + 1) {
            large.push(small.top());
            small.pop();
        } else if (small.size() + 1 < large.size()) {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        if (small.size() == large.size())
            return small.empty() ? 0 : (small.top() + large.top()) / 2.0;
        else
            return small.size() > large.size() ? small.top() : large.top();
    }
};

//  !https://leetcode.com/problems/find-median-from-data-stream/discuss/74091/A-clean-solution-using-multiset-in-C%2B%2B
//  !https://leetcode.com/problems/find-median-from-data-stream/discuss/74166/Solution-using-Binary-Search-Tree
//  !https://leetcode.com/problems/find-median-from-data-stream/discuss/74119/18ms-beats-100-Java-Solution-with-BST