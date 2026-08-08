// Link: https://leetcode.com/problems/least-operators-to-express-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        unordered_map<long long, long long> memo;
        return (int)solve(x, target, memo);
    }

private:
    long long solve(long long x, long long target, unordered_map<long long,long long>& memo) {
        if (target == 0) return 0;
        if (x == 1) return target;
        if (target < x) return min(2 * target - 1, 2 * (x - target));
        if (memo.count(target)) return memo[target];

        long long k = 1, p = x;
        while (p * x <= target) { p *= x; k++; }

        long long ans;
        if (p == target) {
            ans = k - 1;
        } else {
            ans = k + solve(x, target - p, memo);
            if (p * x - target < target) {
                ans = min(ans, k + 1 + solve(x, p * x - target, memo));
            }
        }
        memo[target] = ans;
        return ans;
    }
};
