/*
  Problem link    :
  https://leetcode.com/problems/largest-component-size-by-common-factor/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Normal DFS
class Solution {
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj, int &cnt) {
        vis[node] = true;
        cnt++;
        for (auto nbr : adj[node]) {
            if (!vis[nbr]) {
                dfs(nbr, vis, adj, cnt);
            }
        }
    }

   public:
    int largestComponentSize(vector<int> &nums) {
        vector<vector<int>> adj(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (__gcd(nums[i], nums[j]) != 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(nums.size(), false);
        int sizeOfLComponent = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!vis[i]) {
                int cnt = 0;
                dfs(i, vis, adj, cnt);
                sizeOfLComponent = max(sizeOfLComponent, cnt);
            }
        }
        return sizeOfLComponent;
    }
};