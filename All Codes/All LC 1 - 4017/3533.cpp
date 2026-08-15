// Link: https://leetcode.com/problems/concatenated-divisibility/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n * n * k)  SC: O(2^n * k)
// Approach: bitmask DP over (used-elements mask, remainder mod k) tracking
// whether the remaining unused elements can be arranged to bring the
// remainder to 0 by the end (reachable[mask][r]), computed top-down via
// memoized recursion. Then greedily build the answer: at each step try
// unused elements in ascending numeric order and pick the first whose
// resulting remainder still has a feasible completion — this greedy choice
// yields the lexicographically smallest valid array.
class Solution
{
public:
    vector<int> concatenatedDivisibility(vector<int> &nums, int k)
    {
        int n = nums.size();
        ranges::sort(nums);

        vector<int> wv(n);
        for (int i = 0; i < n; i++)
            wv[i] = (int)to_string(nums[i]).size();
        int w = accumulate(wv.begin(), wv.end(), 0);

        vector<int> fac(w + 1);
        fac[0] = 1 % k;
        for (int i = 1; i <= w; i++)
            fac[i] = fac[i - 1] * 10 % k;

        vector<int8_t> memo((size_t)(1 << n) * k, -1);
        vector<int> path;

        auto dfs = [&](this auto &&dfs, int mask, int rem, int wlen) -> bool
        {
            if (wlen == 0)
                return rem == 0;
            int8_t &m = memo[mask * k + rem];
            if (m != -1)
                return m;
            m = 0;
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                    continue;
                if (i > 0 && nums[i] == nums[i - 1] && !(mask & (1 << (i - 1))))
                    continue;
                int w_tail = wlen - wv[i];
                int nrem = (rem + nums[i] * fac[w_tail]) % k;
                path.push_back(nums[i]);
                if (dfs(mask | (1 << i), nrem, w_tail))
                    return true;
                path.pop_back();
            }
            return m = false;
        };

        dfs(0, 0, w);
        return path;
    }
};
