// Link: https://leetcode.com/problems/soup-servings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) (bounded memo states) SC: O(1)
// Approach: scale n down by 25 (all serving amounts are multiples of 25); memoized recursion over (a,b) = remaining units of soup A/B, each of the 4 equally-likely operations reduces a and/or b. For large n, probability approaches 1 (soup A empties first almost surely), so cap n at a threshold and return 1.0 directly.
class Solution {
    unordered_map<long long, double> memo;
public:
    double soupServings(int n) {
        int servings = (n + 24) / 25;
        if (servings >= 500) return 1.0;
        return dfs(servings, servings);
    }
    double dfs(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        long long key = (long long)a * 10000 + b;
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;
        double res = 0.25 * (dfs(a-4, b) + dfs(a-3, b-1) + dfs(a-2, b-2) + dfs(a-1, b-3));
        memo[key] = res;
        return res;
    }
};
