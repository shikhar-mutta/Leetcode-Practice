// Link: https://leetcode.com/problems/two-best-non-overlapping-events/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), [](auto& a, auto& b) { return a[0] < b[0]; });
        vector<int> starts(n);
        for (int i = 0; i < n; i++) starts[i] = events[i][0];
        vector<int> sufMax(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) sufMax[i] = max(sufMax[i + 1], events[i][2]);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, events[i][2]);
            int idx = upper_bound(starts.begin(), starts.end(), events[i][1]) - starts.begin();
            if (idx < n) ans = max(ans, events[i][2] + sufMax[idx]);
        }
        return ans;
    }
};
