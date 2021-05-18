/*
  Problem Link    :   https://leetcode.com/problems/course-schedule-ii/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Time Complexity - O(V+E)
//  Space Complexity - O(V+E)
//  Using Set
class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> graph(numCourses);
        for (auto p : prerequisites) {
            graph[p[1]].push_back(p[0]), indegree[p[0]]++;
        }
        set<pair<int, int>> sp;
        for (int i = 0; i < numCourses; i++) {
            sp.insert({indegree[i], i});
        }
        vector<int> ans;
        while (!sp.empty()) {
            auto pair = *(sp.begin());
            if (pair.first) {
                ans.clear();
                break;
            }
            ans.push_back(pair.second);
            sp.erase(pair);
            for (auto k : graph[pair.second]) {
                if (indegree[k])
                    sp.erase({indegree[k], k}), indegree[k]--,
                        sp.insert({indegree[k], k});
            }
        }
        return ans;
    }
};

//  Time Complexity - O(V+E)
//  Space Complexity - O(V+E)
//  Using Kahn's Algorithm
class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> graph(numCourses);
        vector<int> ans(numCourses);
        for (auto p : prerequisites) {
            graph[p[1]].push_back(p[0]), indegree[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        int i = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            ans[i++] = node;
            for (auto nbr : graph[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        if (i == numCourses) return ans;
        return {};
    }
};

//  Time Complexity - O(V+E)
//  Space Complexity - O(V+E)
//  Using DFS
class Solution {
   public:
    int white = 1, gray = 2, black = 3;
    vector<vector<int>> graph;
    vector<int> topologicalOrder;
    bool isPossible = true;
    map<int, int> color;

    void dfs(int node) {
        if (!isPossible) return;
        color[node] = gray;
        for (auto nbr : graph[node]) {
            if (color[nbr] == white) {
                dfs(nbr);
            } else if (color[nbr] == gray) {
                isPossible = false;
            }
        }
        color[node] = black;
        topologicalOrder.push_back(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        graph.resize(numCourses);
        for (int i = 0; i < numCourses; i++) {
            color[i] = white;
        }
        for (auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (color[i] == white) {
                dfs(i);
            }
        }
        vector<int> ans(numCourses);
        if (isPossible) {
            for (int i = 0; i < numCourses; i++) {
                ans[i] = topologicalOrder[numCourses - i - 1];
            }
        } else {
            ans.clear();
        }
        return ans;
    }
};