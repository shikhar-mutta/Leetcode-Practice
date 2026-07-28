// Link: https://leetcode.com/problems/distribute-repeating-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;
        vector<int> counts;
        for (auto& [k, v] : freq) counts.push_back(v);
        int k = quantity.size();
        int full = 1 << k;
        vector<int> sumMask(full, 0);
        for (int m = 1; m < full; m++) {
            int lb = m & (-m);
            int idx = __builtin_ctz(lb);
            sumMask[m] = sumMask[m ^ lb] + quantity[idx];
        }
        vector<char> dp(full, false);
        dp[0] = true;
        for (int c : counts) {
            if (dp[full - 1]) break;
            for (int mask = full - 1; mask >= 0; mask--) {
                if (!dp[mask]) continue;
                int rem = (full - 1) ^ mask;
                // iterate submasks of rem
                for (int sub = rem; sub > 0; sub = (sub - 1) & rem) {
                    if (sumMask[sub] <= c) dp[mask | sub] = true;
                }
            }
        }
        return dp[full - 1];
    }
};
