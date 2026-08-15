// Link: https://leetcode.com/problems/kill-process/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: build parent->children adjacency map, then BFS/DFS from kill target collecting all descendants.
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> children;
        int n = pid.size();
        for (int i = 0; i < n; i++) children[ppid[i]].push_back(pid[i]);
        vector<int> res;
        queue<int> q;
        q.push(kill);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            res.push_back(cur);
            for (int c : children[cur]) q.push(c);
        }
        return res;
    }
};
