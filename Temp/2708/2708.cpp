// Link: https://leetcode.com/problems/maximum-strength-of-a-group/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        long long best = LLONG_MIN;
        for (int mask = 1; mask < (1 << n); mask++) {
            long long prod = 1;
            for (int i = 0; i < n; i++)
                if (mask & (1 << i)) prod *= nums[i];
            best = max(best, prod);
        }
        return best;
    }
};
