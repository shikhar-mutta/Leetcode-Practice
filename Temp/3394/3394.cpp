// Link: https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool countGroups(vector<pair<int,int>> intervals) {
        sort(intervals.begin(), intervals.end());
        int groups = 1;
        int curEnd = intervals[0].second;
        for (int i = 1; i < (int)intervals.size(); i++) {
            if (intervals[i].first >= curEnd) {
                groups++;
                curEnd = intervals[i].second;
            } else {
                curEnd = max(curEnd, intervals[i].second);
            }
        }
        return groups >= 3;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> xs, ys;
        for (auto& r : rectangles) {
            xs.push_back({r[0], r[2]});
            ys.push_back({r[1], r[3]});
        }
        return countGroups(xs) || countGroups(ys);
    }
};
