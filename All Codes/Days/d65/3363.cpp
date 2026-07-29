// Link: https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2), SC: O(N)
// Approach: child1's move set forces it onto the main diagonal with no freedom (row and col
// must both increase by exactly 1 every step to cover n-1 steps each way), so its contribution
// is just sum(fruits[i][i]). For child2, col-row is provably non-increasing each step (starts
// positive, must end at 0), so it stays in the col>=row region the whole trip — likewise child3
// stays in row>=col — meaning child2 and child3 only ever meet the diagonal (child1's territory)
// and never collide with each other. DP each of their optimal paths independently, treating
// diagonal cells as 0 (already credited to child1), and sum all three contributions.
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        const int NEG = INT_MIN / 2;

        long long ans = 0;
        for (int i = 0; i < n; i++) ans += fruits[i][i];

        auto val = [&](int r, int c) { return (r == c) ? 0 : fruits[r][c]; };

        // child2: starts (0, n-1), moves increase row by 1, col by -1/0/+1
        vector<int> dp2(n, NEG);
        dp2[n-1] = val(0, n-1);
        for (int r = 1; r < n; r++) {
            vector<int> ndp(n, NEG);
            for (int c = 0; c < n; c++) {
                int best = NEG;
                if (c-1 >= 0 && dp2[c-1] > NEG) best = max(best, dp2[c-1]);
                if (dp2[c] > NEG) best = max(best, dp2[c]);
                if (c+1 < n && dp2[c+1] > NEG) best = max(best, dp2[c+1]);
                if (best > NEG) ndp[c] = best + val(r, c);
            }
            dp2 = ndp;
        }
        ans += dp2[n-1];

        // child3: starts (n-1, 0), moves increase col by 1, row by -1/0/+1
        vector<int> dp3(n, NEG);
        dp3[n-1] = val(n-1, 0);
        for (int c = 1; c < n; c++) {
            vector<int> ndp(n, NEG);
            for (int r = 0; r < n; r++) {
                int best = NEG;
                if (r-1 >= 0 && dp3[r-1] > NEG) best = max(best, dp3[r-1]);
                if (dp3[r] > NEG) best = max(best, dp3[r]);
                if (r+1 < n && dp3[r+1] > NEG) best = max(best, dp3[r+1]);
                if (best > NEG) ndp[r] = best + val(r, c);
            }
            dp3 = ndp;
        }
        ans += dp3[n-1];

        return (int)ans;
    }
};
