// Link: https://leetcode.com/problems/aggregate-two-time-series/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long valueAt(vector<vector<int>>& series, long long t) {
        int lo = 0, hi = series.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (series[mid][0] >= t) hi = mid;
            else lo = mid + 1;
        }
        if (lo == (int)series.size()) return 0;
        return series[lo][1];
    }

    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<int> timestamps;
        for (auto& p : series1) timestamps.push_back(p[0]);
        for (auto& p : series2) timestamps.push_back(p[0]);
        sort(timestamps.begin(), timestamps.end());
        timestamps.erase(unique(timestamps.begin(), timestamps.end()), timestamps.end());

        vector<vector<int>> ans;
        ans.reserve(timestamps.size());
        for (int t : timestamps) {
            long long v = valueAt(series1, t) + valueAt(series2, t);
            ans.push_back({t, (int)v});
        }
        return ans;
    }
};
