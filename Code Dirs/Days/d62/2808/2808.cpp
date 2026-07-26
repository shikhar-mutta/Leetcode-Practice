// Link: https://leetcode.com/problems/minimum-seconds-to-equalize-a-circular-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)
// SC: O(n)
// Approach: each second, every index can copy either neighbor's value, so a
// value spreads outward by 1 index per second in both directions
// simultaneously. For each distinct value, group its (circular) occurrence
// indices; the max gap between consecutive occurrences (wrapping around)
// determines how long that value takes to fill its whole gap, needing
// ceil(gap/2) seconds since it's approached from both sides. The answer is
// the minimum, over all values, of that value's worst gap.
class Solution {
public:
    int minimumSeconds(vector<int>& b) {
        int n = b.size(), ans = INT_MAX, d = 0, st;
        vector<pair<int, int>> a;

        for (int i = 0; i < n; ++i)
            a.push_back({b[i], i});

        sort(a.begin(), a.end()), st = a[0].second;

        for (int i = 1; i < n; ++i) {
            if (a[i].first != a[i - 1].first) {
                d = max(d, st + n - 1 - a[i - 1].second), st = a[i].second;
                ans = min(ans, (d / 2) + (d % 2)), d = 0;
            } else
                d = max(d, a[i].second - a[i - 1].second - 1);
        }

        d = max(d, st + n - 1 - a[n - 1].second),
        ans = min(ans, (d / 2) + (d % 2));
        return ans;
    }
};
