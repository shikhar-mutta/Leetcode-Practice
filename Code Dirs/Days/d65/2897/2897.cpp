// Link: https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*30), SC: O(30)
// Approach: AND/OR operations can freely redistribute set bits among the array (each bit
// position's total count is preserved but can be reassigned to any numbers). To maximize sum of
// squares, concentrate bits into as few numbers as possible: count how many numbers have each
// bit set, then greedily assign each bit to the first min(k, count) of k target "buckets".
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9+7;
        vector<int> cnt(30, 0);
        for (int x : nums)
            for (int b = 0; b < 30; b++)
                if ((x >> b) & 1) cnt[b]++;

        vector<long long> result(k, 0);
        for (int b = 0; b < 30; b++) {
            int limit = min(k, cnt[b]);
            for (int i = 0; i < limit; i++) result[i] |= (1LL << b);
        }

        long long ans = 0;
        for (long long r : result) ans = (ans + r % MOD * (r % MOD)) % MOD;
        return (int)ans;
    }
};
