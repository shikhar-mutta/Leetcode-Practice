// Link: https://leetcode.com/problems/sum-of-subsequence-widths/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(1)
// Approach: sort nums. Each element at sorted index i acts as the max
// of 2^i subsequences (choosing any subset of the i smaller elements to
// include with it) and as the min of 2^(n-1-i) subsequences, so its net
// contribution to the total width sum is nums[i] * (2^i - 2^(n-1-i)).
// Precompute powers of 2 mod 1e9+7 and sum contributions.
class Solution
{
public:
    int sumSubseqWidths(vector<int> &nums)
    {
        constexpr int kMod = 1e9 + 7;
        const int n = nums.size();
        long ans = 0;
        long exp = 1;

        ranges::sort(nums);

        for (int i = 0; i < n; ++i, exp = exp * 2 % kMod)
        {
            ans += (nums[i] - nums[n - 1 - i]) * exp;
            ans %= kMod;
        }

        return ans;
    }
};