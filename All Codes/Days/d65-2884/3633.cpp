// Link: https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int best = INT_MAX;
        for (int i = 0; i < n; i++) {
            int finishLand = landStartTime[i] + landDuration[i];
            for (int j = 0; j < m; j++) {
                int finishWater = waterStartTime[j] + waterDuration[j];
                int lw = max(finishLand, waterStartTime[j]) + waterDuration[j];
                int wl = max(finishWater, landStartTime[i]) + landDuration[i];
                best = min({best, lw, wl});
            }
        }
        return best;
    }
};
