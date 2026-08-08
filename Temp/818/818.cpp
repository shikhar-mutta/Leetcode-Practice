// Link: https://leetcode.com/problems/race-car/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(target log target) SC: O(target)
// Approach: dp[t] = min instructions to reach position t (assuming we never overshoot needlessly, since undershooting via reverses is always optimal to consider). For each t, find k = number of forward moves such that 2^k-1 >= t. If exactly equal, dp[t]=k. Otherwise consider: (a) reverse after some j<k forward moves and continue, ending short and driving back — dp[t-(2^(k-1)-2^j)] + k-1+j+2 for j in 0..k-2; (b) overshoot to 2^k-1 then reverse back — dp[2^k-1-t] + k+1.
class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target+1, 0);
        for (int t = 1; t <= target; t++) {
            dp[t] = INT_MAX;
            int k = 1;
            while ((1 << k) - 1 < t) k++;
            if ((1 << k) - 1 == t) {
                dp[t] = k;
            } else {
                for (int j = 0; j < k-1; j++) {
                    int back = (1 << (k-1)) - (1 << j);
                    dp[t] = min(dp[t], dp[t - back] + k - 1 + j + 2);
                }
                dp[t] = min(dp[t], dp[(1 << k) - 1 - t] + k + 1);
            }
        }
        return dp[target];
    }
};
