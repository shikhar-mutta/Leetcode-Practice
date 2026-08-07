// Link: https://leetcode.com/problems/frog-jump/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n^2)
// Approach: DFS with memoization on (stone index, last jump size); at each
// stone try jump-1, jump, jump+1 to the next reachable stone
class Solution {
    unordered_map<int, int> idxOf;
    unordered_map<long long, int> memo;

    bool dfs(vector<int>& stones, int i, int jump) {
        if (i == (int)stones.size() - 1) return true;
        long long key = (long long)i * 100000 + jump;
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        bool result = false;
        for (int j = jump - 1; j <= jump + 1 && !result; j++) {
            if (j <= 0) continue;
            auto next = idxOf.find(stones[i] + j);
            if (next != idxOf.end()) result = dfs(stones, next->second, j);
        }
        memo[key] = result;
        return result;
    }

public:
    bool canCross(vector<int>& stones) {
        for (int i = 0; i < (int)stones.size(); i++) idxOf[stones[i]] = i;
        if (stones[1] != 1) return false;
        return dfs(stones, 1, 1);
    }
};
