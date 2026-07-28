// Link: https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * 27)  SC: O(1)
// Approach: key insight — the "active" finger (the one that just typed)
// is always at position word[i-1], deterministic regardless of path.
// So the DP state only needs to track the IDLE finger's position (or
// 26 = "not yet placed"). At each step, either the active finger types
// the next char (idle unchanged), or the idle finger types it (cost 0
// if placing it for the first time, else its keyboard distance), and
// the idle finger becomes the old active position.
class Solution {
    int dist(int a, int b) {
        int ax = a / 6, ay = a % 6, bx = b / 6, by = b % 6;
        return abs(ax - bx) + abs(ay - by);
    }
public:
    int minimumDistance(string word) {
        int n = word.size();
        if (n <= 1) return 0;
        vector<int> dp(27, INT_MAX);
        dp[26] = 0;

        for (int i = 1; i < n; i++) {
            int prev = word[i - 1] - 'A';
            int cur = word[i] - 'A';
            vector<int> ndp(27, INT_MAX);
            for (int idle = 0; idle < 27; idle++) {
                if (dp[idle] == INT_MAX) continue;
                int costA = dist(prev, cur);
                ndp[idle] = min(ndp[idle], dp[idle] + costA);

                int costB = (idle == 26) ? 0 : dist(idle, cur);
                ndp[prev] = min(ndp[prev], dp[idle] + costB);
            }
            dp = ndp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
