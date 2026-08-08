// Link: https://leetcode.com/problems/jump-game-iv/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        unordered_map<int, vector<int>> byVal;
        for (int i = 0; i < n; i++) byVal[arr[i]].push_back(i);

        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                int i = q.front(); q.pop();
                if (i == n - 1) return steps;

                if (byVal.count(arr[i])) {
                    for (int j : byVal[arr[i]]) {
                        if (!visited[j]) {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                    byVal.erase(arr[i]);
                }
                if (i + 1 < n && !visited[i+1]) { visited[i+1] = true; q.push(i+1); }
                if (i - 1 >= 0 && !visited[i-1]) { visited[i-1] = true; q.push(i-1); }
            }
            steps++;
        }
        return -1;
    }
};
