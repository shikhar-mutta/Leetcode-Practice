// Link: https://leetcode.com/problems/sum-of-floored-pairs/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(maxVal log maxVal)  SC: O(maxVal)
// Approach: for each distinct value v with freq[v] occurrences, sum over
// multiples k*v of freq[v] * k * (count of numbers in range [k*v, (k+1)*v-1]),
// using a prefix-count array, giving harmonic-series total complexity.
class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;
        vector<long long> prefix(mx + 2, 0);
        for (int i = 1; i <= mx; i++) prefix[i+1] = prefix[i] + freq[i];

        long long ans = 0;
        for (int v = 1; v <= mx; v++) {
            if (freq[v] == 0) continue;
            for (int k = 1; k * v <= mx; k++) {
                int lo = k * v, hi = min(mx, (k+1)*v - 1);
                long long cntInRange = prefix[hi+1] - prefix[lo];
                ans = (ans + (long long)freq[v] * k % MOD * cntInRange) % MOD;
            }
        }
        return (int)ans;
    }
};
