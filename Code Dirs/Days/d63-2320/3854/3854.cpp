// Link: https://leetcode.com/problems/minimum-operations-to-make-array-parity-alternating/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: try both alternating targets (even indices want parity k,
// odd indices want the opposite) — count mismatches for each. For a
// mismatched element, nudging it by +-1 costs the required single
// operation and we choose the direction toward the array's original
// min/max to shrink the eventual spread (push the global min up, the
// global max down; interior values direction doesn't matter for the
// bound). Pick the target with fewer operations, tie-broken by the
// smaller resulting max-min.
class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return {0, 0};

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        auto f = [&](int k) -> vector<int> {
            int cnt = 0;
            int a = INT_MAX, b = INT_MIN;
            for (int i = 0; i < n; i++) {
                int x = nums[i];
                if (((x - i) & 1) != k) {
                    cnt++;
                    if (x == mn) x++;
                    else if (x == mx) x--;
                }
                a = min(a, x);
                b = max(b, x);
            }
            return {cnt, max(1, b - a)};
        };

        vector<int> r0 = f(0), r1 = f(1);
        return r0 < r1 ? r0 : r1;
    }
};
