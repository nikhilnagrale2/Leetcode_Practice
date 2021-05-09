/*
  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

vector<int> adj[1000001];
vector<int> vis(1000001, 0);
vector<int> indegree(1000001, 0);

vector<int> res;
queue<int> q;

void kahn() {
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        res.push_back(node);
        for (auto nbr : adj[node]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    res.clear();
    for (int i = 1; i <= n; i++) adj[i].clear(), indegree[i] = 0, vis[i] = 0;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    kahn();
    if (res.size() != n) {
        cout << "Sandro fails." << endl;
        return;
    }
    for (auto x : res) {
        cout << x << " ";
    }
    cout << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }

    return 0;
}