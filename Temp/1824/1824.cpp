// Link: https://leetcode.com/problems/minimum-sideway-jumps/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> dp = {1, 0, 1};
        for (int i = 1; i < n; i++) {
            vector<int> ndp(3, INT_MAX);
            for (int lane = 0; lane < 3; lane++) {
                if (obstacles[i] != lane + 1) ndp[lane] = dp[lane];
            }
            for (int lane = 0; lane < 3; lane++) {
                if (ndp[lane] == INT_MAX) continue;
                for (int other = 0; other < 3; other++) {
                    if (other == lane) continue;
                    if (obstacles[i] == other + 1) continue;
                    ndp[other] = min(ndp[other], ndp[lane] + 1);
                }
            }
            dp = ndp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
