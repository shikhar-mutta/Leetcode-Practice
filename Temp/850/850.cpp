// Link: https://leetcode.com/problems/rectangle-area-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const long long MOD = 1e9 + 7;
        vector<int> xs;
        for (auto& r : rectangles) { xs.push_back(r[0]); xs.push_back(r[2]); }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        long long total = 0;
        for (int i = 0; i + 1 < (int)xs.size(); i++) {
            long long xw = xs[i+1] - xs[i];
            if (xw == 0) continue;
            vector<pair<int,int>> intervals;
            for (auto& r : rectangles) {
                if (r[0] <= xs[i] && r[2] >= xs[i+1]) {
                    intervals.push_back({r[1], r[3]});
                }
            }
            sort(intervals.begin(), intervals.end());
            long long ySum = 0;
            int curStart = -1, curEnd = -1;
            for (auto& iv : intervals) {
                if (iv.first > curEnd) {
                    if (curEnd != -1) ySum += curEnd - curStart;
                    curStart = iv.first;
                    curEnd = iv.second;
                } else {
                    curEnd = max(curEnd, iv.second);
                }
            }
            if (curEnd != -1) ySum += curEnd - curStart;
            total = (total + (xw % MOD) * (ySum % MOD)) % MOD;
        }
        return (int)total;
    }
};
