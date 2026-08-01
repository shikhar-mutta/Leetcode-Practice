// Link: https://leetcode.com/problems/minimum-operations-to-equalize-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((n+q) log n)  SC: O(n log n)
//  Approach: one operation is +-k on a single element, so a query range is
//  solvable only if every element shares the same remainder mod k (checked
//  via a prefix count of remainder-changes). When solvable, scale values by
//  vals[i]=nums[i]/k (exact, since remainders match) and the answer is
//  sum(|vals[i]-median|), the classic minimize-sum-of-absolute-deviations
//  result. A persistent segment tree over compressed vals (one version per
//  prefix) lets each range query find the median and its left-side
//  count/sum in a single O(log n) top-down descent, giving the answer in
//  closed form without walking the range.
// Wavelet tree with static arrays for cache-friendly access
static int wt_left[16][40001];
static long long wt_sum[16][40001];

class Solution
{
public:
    vector<long long> minOperations(vector<int> &nums, int k,
                                    vector<vector<int>> &queries)
    {
        int n = nums.size(), q = queries.size();

        vector<int> pbad(n, 0);
        for (int i = 1; i < n; i++)
            pbad[i] = pbad[i - 1] + (nums[i] % k != nums[i - 1] % k ? 1 : 0);

        vector<int> val(n);
        for (int i = 0; i < n; i++)
            val[i] = nums[i] / k;

        // Coordinate compression
        vector<int> sv = val;
        sort(sv.begin(), sv.end());
        sv.erase(unique(sv.begin(), sv.end()), sv.end());
        int m = sv.size();
        vector<int> comp(n);
        for (int i = 0; i < n; i++)
            comp[i] = lower_bound(sv.begin(), sv.end(), val[i]) - sv.begin();

        // Pad m to next power of 2
        int levels = 0;
        int sigma = 1;
        while (sigma < m)
        {
            sigma <<= 1;
            levels++;
        }
        if (levels == 0)
            levels = 1, sigma = 2; // handle m=1

        // Build wavelet tree
        // At each level, wt_left[lv][i] = count of left-going elements in [0,
        // i) wt_sum[lv][i] = sum of original values of left-going elements in
        // [0, i)
        vector<int> cur(n), nxt(n);
        for (int i = 0; i < n; i++)
            cur[i] = comp[i];

        // Precompute original values for each position at each level
        vector<long long> cur_val(n), nxt_val(n);
        for (int i = 0; i < n; i++)
            cur_val[i] = sv[comp[i]];

        for (int lv = 0; lv < levels; lv++)
        {
            int bit = levels - 1 - lv;
            wt_left[lv][0] = 0;
            wt_sum[lv][0] = 0;

            int lp = 0, rp = 0;
            // Count total left to find offset for right elements
            int total_left = 0;
            for (int i = 0; i < n; i++)
                if (!((cur[i] >> bit) & 1))
                    total_left++;

            // Build prefix counts and rearrange
            int li = 0, ri = total_left;
            for (int i = 0; i < n; i++)
            {
                bool goes_left = !((cur[i] >> bit) & 1);
                wt_left[lv][i + 1] = wt_left[lv][i] + (goes_left ? 1 : 0);
                wt_sum[lv][i + 1] =
                    wt_sum[lv][i] + (goes_left ? cur_val[i] : 0);
                if (goes_left)
                {
                    nxt[li] = cur[i];
                    nxt_val[li] = cur_val[i];
                    li++;
                }
                else
                {
                    nxt[ri] = cur[i];
                    nxt_val[ri] = cur_val[i];
                    ri++;
                }
            }
            swap(cur, nxt);
            swap(cur_val, nxt_val);
        }

        // Total prefix sum for computing total_sum in any range
        vector<long long> total_prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            total_prefix[i + 1] = total_prefix[i] + sv[comp[i]];

        // Query: kth smallest and sum of first k elements in [l, r]
        auto kth_and_sum = [&](int l, int r,
                               int kk) -> pair<long long, long long>
        {
            long long sum = 0;
            int ql = l, qr = r + 1; // half-open

            for (int lv = 0; lv < levels; lv++)
            {
                int left_in_range = wt_left[lv][qr] - wt_left[lv][ql];
                long long sum_left = wt_sum[lv][qr] - wt_sum[lv][ql];

                int total_left_n = wt_left[lv][n];

                if (kk <= left_in_range)
                {
                    // Go left
                    ql = wt_left[lv][ql];
                    qr = wt_left[lv][qr];
                }
                else
                {
                    // Go right
                    sum += sum_left;
                    kk -= left_in_range;
                    int right_before_ql = ql - wt_left[lv][ql];
                    int right_in_range = (qr - ql) - left_in_range;
                    ql = total_left_n + right_before_ql;
                    qr = ql + right_in_range;
                }
            }
            // After all levels, ql points to the position of the kth element
            // The value at that position is cur[ql] -> but we don't store that
            // Instead, use cur_val: after building, cur contains the final
            // arrangement Actually we need the value: sum += val * kk But we
            // can get it from: total elements going left above gave us 'sum'
            // and the remaining kk elements all have the same value (the kth
            // value) Get the value from the final cur array
            sum += cur_val[ql] * kk;
            return {cur_val[ql], sum};
        };

        vector<long long> ans(q);
        for (int i = 0; i < q; i++)
        {
            int l = queries[i][0], r = queries[i][1];
            if (pbad[r] - pbad[l] > 0)
            {
                ans[i] = -1;
                continue;
            }
            int cnt = r - l + 1;
            if (cnt <= 1)
            {
                ans[i] = 0;
                continue;
            }

            int med_pos = (cnt + 1) / 2;
            auto [med_val, sum_left] = kth_and_sum(l, r, med_pos);
            long long total_sum = total_prefix[r + 1] - total_prefix[l];
            long long sum_right = total_sum - sum_left;
            int cnt_right = cnt - med_pos;

            ans[i] = (sum_right - (long long)cnt_right * med_val) +
                     ((long long)med_pos * med_val - sum_left);
        }
        return ans;
    }
};
