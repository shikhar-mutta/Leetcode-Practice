// Link: https://leetcode.com/problems/maximize-sum-of-device-ratings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n log n) SC: O(1) extra
// Approach: adding a unit to a device never raises its rating, so the
// optimal move is to make every device a source, sending each one's
// minimum away, then dump ALL those removed minimums onto the single
// device whose second-smallest value is smallest (minimizing the drop
// there). Baseline sum = each device's second-smallest; the chosen dump
// device's rating falls from its second-smallest to the global minimum,
// so subtract that difference once.
class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int n = units[0].size();
        if (n == 1) {
            long long ans = 0;
            for (auto& x : units) ans += x[0];
            return ans;
        }

        long long ans = 0;
        int mn = INT_MAX, mn2 = INT_MAX;
        for (auto& x : units) {
            sort(x.begin(), x.end());
            ans += x[1];
            mn2 = min(mn2, x[1]);
            mn = min(mn, x[0]);
        }
        return ans - (mn2 - mn);
    }
};
