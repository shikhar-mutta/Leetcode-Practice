// Link: https://leetcode.com/problems/minimum-cost-to-acquire-required-items/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) SC: O(1)
// Approach: three candidate strategies: buy only singles, buy only
// "both" bundles up to max(need1,need2), or buy min(need1,need2) bundles
// plus singles for the remainder. Return the cheapest.
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long a = (long long)need1 * cost1 + (long long)need2 * cost2;
        long long b = (long long)costBoth * max(need1, need2);
        long long mn = min(need1, need2);
        long long c = (long long)costBoth * mn + (long long)(need1 - mn) * cost1 + (long long)(need2 - mn) * cost2;
        return min({a, b, c});
    }
};
