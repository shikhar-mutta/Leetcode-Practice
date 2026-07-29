// Link: https://leetcode.com/problems/find-maximum-non-decreasing-array-length/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: dp[i] = max resulting length using nums[0:i] merged into segments, last[i] = the
// value of that final segment (prefix[i]-prefix[j] for the chosen split j). To extend to a new
// segment [j,i), we need its sum >= last[j] (non-decreasing requirement). Since dp is
// non-decreasing in j, we always want the largest feasible j. Since prefix sums grow with i,
// feasibility of any given j only improves as i increases, so a two-pointer that keeps trying to
// push j forward (never backward) finds that largest feasible j in amortized O(N).
class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n+1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];

        vector<int> dp(n+1, 0);
        vector<long long> last(n+1, 0);
        int j = 0;
        for (int i = 1; i <= n; i++) {
            while (j + 1 <= i - 1 && prefix[i] - prefix[j+1] >= last[j+1]) j++;
            dp[i] = dp[j] + 1;
            last[i] = prefix[i] - prefix[j];
        }
        return dp[n];
    }
};
