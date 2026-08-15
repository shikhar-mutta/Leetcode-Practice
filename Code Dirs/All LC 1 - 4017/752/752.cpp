// Link: https://leetcode.com/problems/open-the-lock/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(10^4) SC: O(10^4)
// Approach: BFS over the state space of 4-digit combinations; each state has 8 neighbors (each wheel +1/-1). Skip deadends.
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        string start = "0000";
        if (dead.count(start)) return -1;
        if (target == start) return 0;
        unordered_set<string> visited = {start};
        queue<string> q;
        q.push(start);
        int steps = 0;
        while (!q.empty()) {
            steps++;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front(); q.pop();
                for (int pos = 0; pos < 4; pos++) {
                    for (int d = -1; d <= 1; d += 2) {
                        string next = cur;
                        next[pos] = '0' + (((cur[pos]-'0') + d + 10) % 10);
                        if (next == target) return steps;
                        if (!dead.count(next) && !visited.count(next)) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
