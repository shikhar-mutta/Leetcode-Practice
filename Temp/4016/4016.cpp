// Link: https://leetcode.com/problems/maximum-area-of-two-non-overlapping-square-submatrices/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (mat[r][c] == 0) { dp[r][c] = 0; continue; }
                if (r == 0 || c == 0) dp[r][c] = 1;
                else dp[r][c] = 1 + min({dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1]});
            }
        }

        auto feasible = [&](int k) -> bool {
            int minR = INT_MAX, maxR = INT_MIN, minC = INT_MAX, maxC = INT_MIN;
            int count = 0;
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    if (dp[r][c] >= k) {
                        count++;
                        minR = min(minR, r); maxR = max(maxR, r);
                        minC = min(minC, c); maxC = max(maxC, c);
                    }
                }
            }
            if (count < 2) return false;
            return (maxR - minR >= k) || (maxC - minC >= k);
        };

        int lo = 1, hi = min(m, n), ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(mid)) { ans = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return ans * ans;
    }
};
