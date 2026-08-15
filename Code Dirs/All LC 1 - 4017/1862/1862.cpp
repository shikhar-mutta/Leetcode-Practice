// Link: https://leetcode.com/problems/sum-of-floored-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> cnt(maxVal + 1, 0);
        for (int x : nums) cnt[x]++;
        vector<long long> prefix(maxVal + 1, 0);
        for (int i = 1; i <= maxVal; i++) prefix[i] = prefix[i-1] + cnt[i];

        long long total = 0;
        for (int v = 1; v <= maxVal; v++) {
            if (cnt[v] == 0) continue;
            long long sumForV = 0;
            for (int k = 1; k * v <= maxVal; k++) {
                int lo = k * v;
                int hi = min(maxVal, (k + 1) * v - 1);
                sumForV += (long long)k * (prefix[hi] - prefix[lo - 1]);
            }
            total = (total + (long long)cnt[v] * sumForV) % MOD;
        }
        return (int)total;
    }
};
