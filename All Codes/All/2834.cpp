// Link: https://leetcode.com/problems/find-the-minimum-possible-sum-of-a-beautiful-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach: to minimize the sum of n distinct positive integers with no pair
// summing to target, greedily take 1, 2, ..., m where m = min(n, target/2)
// (these can never pair to target since both values would be < target/2, or
// exactly target/2 paired with itself which can't happen with distinct
// values). Once that range is used up, remaining values must jump to target,
// target+1, ... to stay safe (mirrors 2829's k-avoiding-array structure).
// Both partial sums use the closed-form triangular-number formula computed
// mod 1e9+7 via the modular inverse of 2 (500000004).
class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        const long long MOD = 1000000007;
        long long m = min((long long)n, (long long)target / 2);   // take 1, 2, ..., m

        // sum of 1..m
        long long sum = m % MOD * ((m + 1) % MOD) % MOD;
        sum = sum * 500000004 % MOD;   // multiply by modular inverse of 2

        // remaining n - m numbers starting from target
        long long rem = n - m;
        // sum of target, target+1, ..., target+rem-1
        // = rem * target + rem*(rem-1)/2
        long long part2 = rem % MOD * (target % MOD) % MOD;
        long long tri = rem % MOD * ((rem - 1) % MOD + MOD) % MOD;
        tri = tri * 500000004 % MOD;
        part2 = (part2 + tri) % MOD;

        return (int)((sum + part2) % MOD);
    }
};
