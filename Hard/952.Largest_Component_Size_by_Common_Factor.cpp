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

// Union Find
class DSU {
    vector<int> parent;
    vector<int> ranks;

   public:
    void init(int n) {
        parent.resize(n + 1, 0);
        ranks.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            ranks[i] = 0;
        }
    }

    int findpar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findpar(parent[node]);
    }

    void unionbyrank(int u, int v) {
        u = findpar(u);
        v = findpar(v);
        if (ranks[u] < ranks[v]) {
            parent[u] = v;
        } else if (ranks[v] < ranks[u]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            ranks[u]++;
        }
    }
};

class Solution {
   public:
    int largestComponentSize(vector<int> &nums) {
        int n = size(nums), ans = 1;
        DSU ds;
        ds.init(*max_element(begin(nums), end(nums)) + 1);
        unordered_map<int, int> mp;
        for (auto c : nums) {
            for (int f = 2; f <= sqrt(c); f++) {
                if (c % f == 0) {
                    ds.unionbyrank(c, f), ds.unionbyrank(c, c / f);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            ans = max(ans, ++mp[ds.findpar(nums[i])]);
        }
        return ans;
    }
};