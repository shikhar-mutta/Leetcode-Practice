// Link: https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();

        int minLF = INT_MAX;
        for (int i = 0; i < n; i++) minLF = min(minLF, landStartTime[i] + landDuration[i]);
        int minWF = INT_MAX;
        for (int j = 0; j < m; j++) minWF = min(minWF, waterStartTime[j] + waterDuration[j]);

        int best = INT_MAX;
        for (int j = 0; j < m; j++) {
            int base = (minLF <= waterStartTime[j]) ? waterStartTime[j] : minLF;
            best = min(best, waterDuration[j] + base);
        }
        for (int i = 0; i < n; i++) {
            int base = (minWF <= landStartTime[i]) ? landStartTime[i] : minWF;
            best = min(best, landDuration[i] + base);
        }

        return best;
    }
};
