// Link: https://leetcode.com/problems/rotate-function/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: F(k) = F(k-1) + sum(nums) - n*nums[n-k]; compute F(0) directly,
// then derive each rotation in O(1)
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, f = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            f += (long long)i * nums[i];
        }
        long long best = f;
        for (int k = 1; k < n; k++) {
            f += sum - (long long)n * nums[n - k];
            best = max(best, f);
        }
        return (int)best;
    }
};
