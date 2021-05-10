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

vector<vector<char>> grid(1002, vector<char>(1002));
vector<vector<int>> dist(1002, vector<int>(1002));
int n;

void bfs(int i, int j) {
    int offsets[] = {0, 1, 0, -1, 0};
    queue<pair<int, int>> q;
    q.push({i, j});
    dist[i][j] = 0;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        int d = dist[node.first][node.second];
        for (int k = 0; k < 4; k++) {
            int x = node.first + offsets[k], y = node.second + offsets[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < n &&
                (grid[x][y] == 'P' || grid[x][y] == 'E')) {
                dist[x][y] = d + 1;
                grid[x][y] = 'T';
                q.push({x, y});
            }
        }
    }
}

void solve() {
    int sx, sy, ex, ey;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
                sx = i, sy = j;
            else if (grid[i][j] == 'E')
                ex = i, ey = j;
        }
    }

    bfs(sx, sy);
    cout << dist[ex][ey] << endl;
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