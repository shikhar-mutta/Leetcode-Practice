// Link: https://leetcode.com/problems/maximum-subarray-with-equal-products/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int best = 1;
        for (int i = 0; i < n; i++) {
            long long prod = 1, g = 0, l = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);
                if (prod > (long long)4e18) break; // overflow guard
                if (prod == l * g) best = max(best, j - i + 1);
            }
        }
        return best;
    }
};
