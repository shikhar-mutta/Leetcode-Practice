// Link: https://leetcode.com/problems/find-the-count-of-monotonic-pairs-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*maxVal), SC: O(maxVal)
// Approach: dp[v] = number of ways to choose arr1[i]=v satisfying both monotonicity constraints
// so far. arr1 nondecreasing needs prevV<=v; arr2=nums-arr1 nonincreasing needs
// prevV <= v + nums[i-1]-nums[i]. Combined bound = min(v, v+nums[i-1]-nums[i]); use a prefix sum
// of the previous dp row to sum over all valid prevV in O(1) per v.
class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        const long long MOD = 1e9+7;
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<long long> dp(maxVal+1, 0);
        for (int v = 0; v <= nums[0]; v++) dp[v] = 1;

        for (int i = 1; i < n; i++) {
            vector<long long> prefix(maxVal+2, 0);
            for (int v = 0; v <= maxVal; v++) prefix[v+1] = (prefix[v] + dp[v]) % MOD;

            vector<long long> ndp(maxVal+1, 0);
            int diff = nums[i-1] - nums[i];
            for (int v = 0; v <= nums[i]; v++) {
                int bound = min(v, v + diff);
                if (bound < 0) continue;
                bound = min(bound, maxVal);
                ndp[v] = prefix[bound+1];
            }
            dp = ndp;
        }

        long long ans = 0;
        for (long long x : dp) ans = (ans + x) % MOD;
        return (int)ans;
    }
};
