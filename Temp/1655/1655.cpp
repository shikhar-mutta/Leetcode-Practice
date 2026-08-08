// Link: https://leetcode.com/problems/distribute-repeating-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;
        vector<int> counts;
        for (auto& [k, v] : freq) counts.push_back(v);
        sort(counts.rbegin(), counts.rend());

        int m = quantity.size();
        int full = (1 << m) - 1;
        vector<int> sum(1 << m, 0);
        for (int mask = 1; mask <= full; mask++) {
            int low = mask & (-mask);
            int idx = __builtin_ctz(low);
            sum[mask] = sum[mask ^ low] + quantity[idx];
        }

        vector<bool> dp(1 << m, false);
        dp[0] = true;
        for (int c : counts) {
            vector<bool> ndp = dp;
            for (int mask = 0; mask <= full; mask++) {
                if (!dp[mask]) continue;
                int rem = full ^ mask;
                for (int sub = rem; sub > 0; sub = (sub - 1) & rem) {
                    if (sum[sub] <= c) ndp[mask | sub] = true;
                }
            }
            dp = ndp;
            if (dp[full]) return true;
        }
        return dp[full];
    }
};
