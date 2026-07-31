// Link: https://leetcode.com/problems/maximum-product-of-first-and-last-elements-of-a-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> suffMax(n), suffMin(n);
        suffMax[n-1] = suffMin[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
            suffMax[i] = max(suffMax[i+1], nums[i]);
            suffMin[i] = min(suffMin[i+1], nums[i]);
        }

        long long best = LLONG_MIN;
        for (int i = 0; i + m - 1 < n; i++) {
            int j0 = i + m - 1;
            long long a = (long long)nums[i] * suffMax[j0];
            long long b = (long long)nums[i] * suffMin[j0];
            best = max({best, a, b});
        }

        return best;
    }
};
