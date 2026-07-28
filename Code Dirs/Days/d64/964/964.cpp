// Link: https://leetcode.com/problems/least-operators-to-express-number/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(log(target)^2)  SC: O(log(target))
// Approach: memoized recursion returning the operator cost to build and
// attach a term equal to `t` (including one leading +/- to attach it to
// whatever precedes it — corrected for the true first term via a final
// -1). If x>t, use repeated x/x units (cost 2 each) added or subtracted
// from x. Otherwise find the largest power p=x^k <= t: if exact, cost
// is k (k-1 multiplications + 1 leading op); otherwise recurse on the
// remainder t-p (attach cost k) or overshoot p*x-t (attach cost k+1),
// taking the cheaper.
class Solution {
    unordered_map<long long,long long> memo;
    int x;
    long long dfs(long long t) {
        if (memo.count(t)) return memo[t];
        long long res;
        if (x > t) {
            res = min(2 * t, 2 * (x - t) + 1);
        } else {
            long long k = 0, p = 1;
            while (p * x <= t) { p *= x; k++; }
            if (p == t) {
                res = k;
            } else {
                res = dfs(t - p) + k;
                if (p * x - t < t) res = min(res, dfs(p * x - t) + k + 1);
            }
        }
        memo[t] = res;
        return res;
    }
public:
    int leastOpsExpressTarget(int x, int target) {
        this->x = x;
        memo.clear();
        return (int)(dfs(target) - 1);
    }
};
