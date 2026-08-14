// Link: https://leetcode.com/problems/power-of-heroes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        long long ans = 0, sumMin = 0;
        for (int x : nums) {
            long long v = x;
            ans = (ans + v % MOD * v % MOD * ((v + sumMin) % MOD)) % MOD;
            sumMin = (2 * sumMin + v) % MOD;
        }
        return (int)ans;
    }
};
