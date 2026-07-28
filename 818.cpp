// Link: https://leetcode.com/problems/race-car/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(target log(target))  SC: O(target log(target))
// Approach: memoized DP. dp[t] = min instructions to reach exactly t.
// For each t, try every "accelerate n steps then flip" strategy: drive
// forward 2^n-1 (n A's) then either stop exactly there (if t==2^n-1,
// cost n), or flip and continue toward the remainder (2^n-1-t) with an
// extra reverse move (n+1), or overshoot to 2^n-1+m and flip back
// toward t-(2^n-1+m)... simplified to the two dominant cases per n.
class Solution {
    unordered_map<int,int> memo;
public:
    int racecar(int target) {
        if (memo.count(target)) return memo[target];
        int n = floor(log2(target)) + 1;
        int ans;
        if ((1 << n) - 1 == target) {
            ans = n;
        } else {
            ans = n + 1 + racecar((1 << n) - 1 - target);
            for (int m = 0; m < n - 1; m++) {
                int rem = target - (1 << (n - 1)) + (1 << m);
                ans = min(ans, n - 1 + m + 1 + racecar(rem));
            }
        }
        memo[target] = ans;
        return ans;
    }
};
