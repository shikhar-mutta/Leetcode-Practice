// Link: https://leetcode.com/problems/tallest-billboard/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * sumOfRods)  SC: O(sumOfRods)
// Approach: dp maps (height difference between the two towers) -> the
// maximum achievable shorter-tower height for that difference. For each
// rod, it can be skipped, added to the taller side (diff increases,
// short side unchanged), or added to the shorter side (diff becomes
// |diff-rod|, short side grows by min(diff,rod)). The answer is dp[0]
// (equal towers) at the end.
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int,int> dp;
        dp[0] = 0;
        for (int r : rods) {
            unordered_map<int,int> ndp = dp;
            for (auto& [d, low] : dp) {
                int nd1 = d + r;
                ndp[nd1] = max(ndp.count(nd1) ? ndp[nd1] : 0, low);

                int nd2 = abs(d - r);
                int nlow = low + min(d, r);
                ndp[nd2] = max(ndp.count(nd2) ? ndp[nd2] : 0, nlow);
            }
            dp = ndp;
        }
        return dp[0];
    }
};
