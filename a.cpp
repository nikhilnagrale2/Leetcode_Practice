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
const ll mod = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) cin >> b[i];
    if (a[0] % 2 == 0 && a[0] / 2 == n-1 && b[0] % 3 == 0 && b[0] / 3 == n-1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test = 1;
    cin >> test;
    while (test--) {
        solve();
    }

    return 0;
}