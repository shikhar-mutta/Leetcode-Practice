// Link: https://leetcode.com/problems/sum-of-beautiful-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) where n is the length of the input vector nums.
// SC: O(n) for the bg, idx, sel, tr, and cnts arrays used in the function.
// Approach: The solution uses a greedy approach to calculate the total beauty of all beautiful subsequences in the input vector nums. It first counts the occurrences of each number in the input vector and stores them in the bg array. Then, it iterates through the numbers in descending order and calculates the number of beautiful subsequences for each number using a Fenwick tree (tr array). The final result is the sum of the beauty of all beautiful subsequences, which is returned as the output of the function.
constexpr int mod = 1000000007;
int bg[70001], idx[10001], sel[10000], tr[70000], cnts[70001];

class Solution
{
public:
    int totalBeauty(vector<int> &nums)
    {
        int M = *max_element(begin(nums), end(nums));
        fill(bg, bg + M, 0);
        for (int n : nums)
            ++bg[n - 1];
        for (int i = 1; i < M; ++i)
            bg[i] += bg[i - 1];
        bg[M] = bg[M - 1];
        for (int i = size(nums) - 1; i >= 0; --i)
            idx[--bg[nums[i] - 1]] = i;

        int res = 0;
        for (int g = M; g; --g)
        {
            int p = 0;
            for (int f = g; f <= M; f += g)
                for (int i = bg[f - 1], e = bg[f]; i != e; ++i)
                    sel[p++] = idx[i];
            if (p == 0)
            {
                cnts[g] = 0;
                continue;
            }
            sort(sel, sel + p);

            int m = M / g;
            fill(tr, tr + m, 0);
            long long cnt = 0;
            for (int i = 0; i < p; ++i)
            {
                int n = nums[sel[i]] / g, s = 1;
                for (int p = n - 2; p >= 0; p = (p & (p + 1)) - 1)
                    s = (s + tr[p]) % mod;
                for (int p = n - 1; p < m; p = p | (p + 1))
                    tr[p] = (tr[p] + s) % mod;
                cnt += s;
            }

            for (int f = g + g; f <= M; f += g)
                cnt -= cnts[f];
            cnts[g] = cnt %= mod;
            if (cnt)
                res = (res + cnt * g) % mod;
        }
        return res;
    }
};
