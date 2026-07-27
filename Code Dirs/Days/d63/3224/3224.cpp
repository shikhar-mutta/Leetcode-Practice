// Link: https://leetcode.com/problems/minimum-array-changes-to-make-differences-equal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + k), SC: O(k)
// Approach: For each mirrored pair (nums[i], nums[n-1-i]), changing one or
// both values can make their absolute difference equal to any target d in
// [0,k] at some cost (0 if already d, 1 if achievable by changing just one
// side, else 2). Rather than compute cost per d directly, use a difference
// array: cost is n/2 minus adjustments encoded via range updates around the
// pair's natural diff and the reachable "free" range up to max(a,k-b), then
// take a prefix sum over d in [0,k] to find the minimum total cost.
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
    static constexpr int kmax = 100000;
    inline static int ops[kmax + 2];
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        ops[0] = n / 2;
        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i], b = nums[n - 1 - i];
            if (a < b)
                swap(a, b);
            --ops[a - b];
            ++ops[a - b + 1];
            ++ops[max(a, k - b) + 1];
        }
        int pref = 0;
        int ans = INT_MAX;
        for (int i = 0; i <= k; ++i) {
            ans = min(ans, pref += ops[i]);
            ops[i] = 0;
        }
        ops[k + 1] = 0;
        return ans;
    }
};
