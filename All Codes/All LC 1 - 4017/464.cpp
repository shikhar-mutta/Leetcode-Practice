// Link: https://leetcode.com/problems/can-i-win/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n * n)  SC: O(2^n)
// Approach: bitmask memoized minimax - state = set of used numbers; current
// player wins if any unused number either reaches the target or leaves the
// opponent in a losing state
class Solution {
    unordered_map<int, int> memo; // 1 = win, -1 = lose

    bool dfs(int mask, int remaining, int n) {
        auto it = memo.find(mask);
        if (it != memo.end()) return it->second == 1;

        for (int i = 1; i <= n; i++) {
            if (mask & (1 << i)) continue;
            if (i >= remaining || !dfs(mask | (1 << i), remaining - i, n)) {
                memo[mask] = 1;
                return true;
            }
        }
        memo[mask] = -1;
        return false;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) return true;
        int total = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (total < desiredTotal) return false;
        return dfs(0, desiredTotal, maxChoosableInteger);
    }
};
