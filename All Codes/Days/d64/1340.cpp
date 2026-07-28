// Link: https://leetcode.com/problems/jump-game-v/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * d)  SC: O(n)
// Approach: memoized DFS. From index i, jump to any j within distance d
// (in either direction) with all values strictly between i and j
// shorter than arr[i] (and arr[j] < arr[i]) — the value-strictly-
// decreasing requirement guarantees the recursion is acyclic, so plain
// memoization suffices. dp[i] = 1 + max jumps reachable from i.
class Solution {
    vector<int> memo;
    int dfs(vector<int>& arr, int i, int d) {
        if (memo[i] != -1) return memo[i];
        int best = 1;
        int n = arr.size();
        for (int dir = -1; dir <= 1; dir += 2) {
            for (int step = 1; step <= d; step++) {
                int j = i + dir * step;
                if (j < 0 || j >= n || arr[j] >= arr[i]) break;
                best = max(best, 1 + dfs(arr, j, d));
            }
        }
        memo[i] = best;
        return best;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        memo.assign(n, -1);
        int ans = 1;
        for (int i = 0; i < n; i++) ans = max(ans, dfs(arr, i, d));
        return ans;
    }
};
