// Link: https://leetcode.com/problems/maximize-pair-strength-using-gcd/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long best = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long g = __gcd(nums[i], nums[j]);
                long long strength = (long long)nums[i] * nums[j] / (g * g);
                best = max(best, strength);
            }
        }
        return best;
    }
};
