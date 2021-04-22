/*
  Problem Link    :   https://leetcode.com/problems/minimum-window-substring/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//	Sliding Window
//	Time Complexity - O(|s|+|t|)
//	Space Complexity - O(|s|+|t|)
class Solution {
   public:
    string minWindow(string s, string t) {
        if (!s.size() || !t.size()) return "";
        map<char, int> tmap;
        for (auto x : t) {
            tmap[x]++;
        }
        vector<int> ans = {-1, 0};
        int req = tmap.size();
        int l = 0, r = 0;
        int formed = 0;
        map<char, int> cmap;
        while (r < s.size()) {
            char c = s[r];
            cmap[c] += 1;
            if (tmap.find(c) != tmap.end() && cmap[c] == tmap[c]) formed++;
            while (l <= r && formed == req) {
                c = s[l];
                if (ans[0] == -1 || r - l + 1 < ans[0]) {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                }
                cmap[c] -= 1;
                if (tmap.find(c) != tmap.end() && cmap[c] < tmap[c]) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
    }
};

//	Sliding Window
