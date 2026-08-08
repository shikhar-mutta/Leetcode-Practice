// Link: https://leetcode.com/problems/time-needed-to-inform-all-employees/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> children(n);
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) children[manager[i]].push_back(i);
        }

        function<int(int)> dfs = [&](int u) -> int {
            int maxTime = 0;
            for (int c : children[u]) maxTime = max(maxTime, dfs(c));
            return informTime[u] + maxTime;
        };

        return dfs(headID);
    }
};
