// Link: https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    static constexpr int nmax = 100000;
    static constexpr int max_abs = 1000000;

    static constexpr int tree_sz = 2 * max_abs + 2;
    static constexpr int bf = bit_floor(1u * (tree_sz - 1));

    inline static pair<long long, int> tree[tree_sz];
    inline static long long min_op[nmax + 1];
    inline static long long dp[nmax + 1];

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        int med_idx = x / 2;

        auto add = [](int i, pair<int, int> p) {
            for (; i < tree_sz; i += (i & -i)) {
                tree[i].first += p.first;
                tree[i].second += p.second;
            }
        };
        auto bl = [](int cnt) {
            long long sum = 0;
            int cnt_so_far = 0;
            int i = 0;
            for (int bit = bf; bit; bit >>= 1)
                if (i + bit < tree_sz &&
                    cnt_so_far + tree[i + bit].second < cnt) {
                    i += bit;
                    sum += tree[i].first;
                    cnt_so_far += tree[i].second;
                }
            return tuple(sum, cnt_so_far, i - max_abs);
        };

        long long total_sum = 0;
        for (int i = 0, j = 0; j < n; ++i) {
            while (j - i < x) {
                add(nums[j] + max_abs + 1, {nums[j], 1});
                total_sum += nums[j];
                ++j;
            }

            auto [sum_left, cnt_left, med_val] = bl(med_idx + 1);
            min_op[j] =
                1ll * med_val * (2 * cnt_left - x) + total_sum - 2 * sum_left;

            add(nums[i] + max_abs + 1, {-nums[i], -1});
            total_sum -= nums[i];
        }
        for (int i = n - x + 1; i < n; ++i)
            add(nums[i] + max_abs + 1, {-nums[i], -1});

        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= k; ++i) {
            for (int j = n; j >= i * x; --j)
                dp[j] = min_op[j] + dp[j - x];
            for (int j = i * x + 1; j <= n; ++j)
                dp[j] = min(dp[j], dp[j - 1]);
        }

        return dp[n];
    }
};
