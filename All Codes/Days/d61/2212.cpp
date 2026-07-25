// Link: https://leetcode.com/problems/maximum-points-in-an-archery-competition/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^12) (exhaustive backtracking over the 12 score sections)
// SC: O(12) recursion depth / result size
// Approach: try, from section 11 down to 1, either committing enough
// arrows to beat Alice at that section (a[ind]+1, scoring ind points) or
// skipping it, exhaustively exploring both branches. Track the best total
// score seen and its arrow allocation; any leftover unused arrows are
// dumped into section 0 (worth nothing, but must be accounted for to use
// up all numArrows).
class Solution {
public:
    vector<int> ans;
    int maxscore = 0;
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> res(12, 0);

        solve(res, numArrows, aliceArrows, 11, 0);
        return ans;
    }
    void solve(vector<int>& res, int num, vector<int>& a, int ind, int curr) {
        if (ind == 0 || num == 0) {
            if (maxscore < curr) {
                maxscore = curr;
                ans = res;
                ans[0] += num;
            }

            return;
        }

        if (a[ind] + 1 <= num) {
            res[ind] = a[ind] + 1;
            solve(res, num - a[ind] - 1, a, ind - 1, curr + ind);
            res[ind] = 0;
        }
        solve(res, num, a, ind - 1, curr);
    }
};
