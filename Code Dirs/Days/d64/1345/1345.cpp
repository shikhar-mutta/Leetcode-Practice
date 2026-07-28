// Link: https://leetcode.com/problems/jump-game-iv/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: BFS where each index connects to i-1, i+1, and every other
// index sharing the same value. To avoid O(n^2) from revisiting same-
// value groups repeatedly, clear each value's index list from the map
// right after using it once (all same-value jumps are explored in a
// single BFS layer anyway, so future layers never need that group again).
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        unordered_map<int, vector<int>> valueIdx;
        for (int i = 0; i < n; i++) valueIdx[arr[i]].push_back(i);

        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                int i = q.front(); q.pop();

                vector<int> next;
                if (valueIdx.count(arr[i])) {
                    for (int j : valueIdx[arr[i]]) next.push_back(j);
                    valueIdx.erase(arr[i]);
                }
                if (i + 1 < n) next.push_back(i + 1);
                if (i - 1 >= 0) next.push_back(i - 1);

                for (int j : next) {
                    if (j == n - 1) return steps + 1;
                    if (!visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
