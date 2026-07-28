// Link: https://leetcode.com/problems/make-array-strictly-increasing/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * m log m)  SC: O(n) states
// Approach: DP over "last value placed" -> minimum replacements so far,
// using a map for compactness. For each element of arr1, either keep it
// (if it exceeds the current last value) or replace it with the
// smallest value from sorted arr2 that exceeds the last value (costing
// one more operation). Collapse to the best (min ops) state per last
// value each step; if no transition survives, it's impossible.
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        map<long long, int> dp;
        dp[LLONG_MIN] = 0;

        for (int num : arr1) {
            map<long long, int> ndp;
            for (auto& [last, ops] : dp) {
                if (num > last) {
                    auto it = ndp.find(num);
                    if (it == ndp.end() || ops < it->second) ndp[num] = ops;
                }
                auto ub = upper_bound(arr2.begin(), arr2.end(), last);
                if (ub != arr2.end()) {
                    long long val = *ub;
                    auto it = ndp.find(val);
                    if (it == ndp.end() || ops + 1 < it->second) ndp[val] = ops + 1;
                }
            }
            if (ndp.empty()) return -1;
            dp = ndp;
        }

        int best = INT_MAX;
        for (auto& [last, ops] : dp) best = min(best, ops);
        return best;
    }
};
