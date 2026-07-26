// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-x-and-y-equal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log x) – at most O(log₅ x + log₁₁ x) unique states, each O(1) work
// SC: O(log x) – memoization map + recursion stack depth
// Approach: Memoized recursion. Allowed ops: ±1 (increment/decrement), ÷11,
// ÷5 (if divisible). Base: x <= y → return y-x (just increment).
// At each x, consider three choices:
//   res1: best cost using ÷11 — if x%11==0: 1+f(x/11); else min of
//         (pad down: x%11 decrements + 1 divide) vs (pad up: 11-x%11 increments + 1 divide)
//   res2: best cost using ÷5  — same logic with 5
//   res3: pure decrement: x-y steps
// dp[x] = min(res1, res2, res3).
class Solution
{
private:
    unordered_map<int, int> dp;
    int f(int x, int y)
    {
        if (x <= y)
            return y - x;
        if (dp.count(x))
            return dp[x];
        int res1 = 1e6;
        if (x % 11 == 0)
        {
            res1 = 1 + f(x / 11, y);
        }
        else
        {
            res1 = min((x % 11 + 1 + f(x / 11, y)),
                       (11 - x % 11 + 1 + f(x / 11 + 1, y)));
        }
        int res2 = 1e6;
        if (x % 5 == 0)
        {
            res2 = 1 + f(x / 5, y);
        }
        else
        {
            res2 = min((x % 5 + 1 + f(x / 5, y)),
                       (5 - x % 5 + 1 + f(x / 5 + 1, y)));
        }
        int res3 = x - y;
        dp[x] = min({res1, res2, res3});
        return dp[x];
    }

public:
    int minimumOperationsToMakeEqual(int x, int y) { return f(x, y); }
};
