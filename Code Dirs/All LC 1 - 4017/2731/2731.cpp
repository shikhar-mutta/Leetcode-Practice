// Link: https://leetcode.com/problems/movement-of-robots/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> pos(n);
        for (int i = 0; i < n; i++) pos[i] = nums[i] + (s[i] == 'R' ? (long long)d : -(long long)d);
        sort(pos.begin(), pos.end());

        long long total = 0, prefixSum = 0;
        for (int i = 0; i < n; i++) {
            total = (total + (pos[i] * i % MOD - prefixSum % MOD + MOD) % MOD) % MOD;
            prefixSum += pos[i];
        }
        return (int)total;
    }
};
