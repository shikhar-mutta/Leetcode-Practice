// Link: https://leetcode.com/problems/xor-after-range-multiplication-queries-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        vector<long long> a(nums.begin(), nums.end());

        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int idx = l; idx <= r; idx += k) {
                a[idx] = (a[idx] * v) % MOD;
            }
        }

        long long result = 0;
        for (long long x : a) result ^= x;
        return (int)result;
    }
};
