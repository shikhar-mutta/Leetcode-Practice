// Link: https://leetcode.com/problems/maximize-subarray-gcd-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * log(max(nums))): Iterate through the array and for each element, calculate the GCD of the subarray ending at that element. For each GCD, we can calculate the maximum score by keeping track of the last k elements with the same GCD.
// SC: O(n): For storing the last k elements with the same GCD.
// Approach: The problem can be solved by iterating through the array and for each element, calculating the GCD of the subarray ending at that element. For each GCD, we can calculate the maximum score by keeping track of the last k elements with the same GCD. We can use a vector to store the last k elements with the same GCD and for each new element, we can update the vector and calculate the maximum score.
using ll = long long;
class Solution
{
public:
    long long maxGCDScore(vector<int> &nums, int k)
    {
        const int n = nums.size();
        int mx = bit_width((uint32_t)ranges::max(nums));
        vector<vector<int>> lowbit_pos(mx);
        ll ans = 0;

        //(l, r]
        struct Interval
        {
            int g, l, r;
        };
        vector<Interval> intervals;
        for (int i = 0; i < n; ++i)
        {
            int &x = nums[i];
            int tz = countr_zero(1u * x);
            lowbit_pos[tz].push_back(i);
            for (auto &p : intervals)
            {
                p.g = gcd(p.g, x);
            }
            intervals.emplace_back(x, i - 1, i);
            int idx = 1;
            for (int j = 1; j < intervals.size(); ++j)
            {
                if (intervals[j].g != intervals[j - 1].g)
                {
                    intervals[idx++] = intervals[j];
                }
                else
                {
                    intervals[idx - 1].r = intervals[j].r;
                }
            }
            intervals.resize(idx);
            for (auto &[g, l, r] : intervals)
            {
                ans = max(ans, 1LL * g * (i - l));
                int tz = countr_zero(1u * g);
                auto &pos = lowbit_pos[tz];
                int minL =
                    pos.size() > k ? max(l, pos[pos.size() - (k + 1)]) : l;
                if (minL < r)
                {
                    ans = max(ans, 2LL * g * (i - minL));
                }
            }
        }
        return ans;
    }
};
