// Link: https://leetcode.com/problems/count-fancy-numbers-in-a-range/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)  SC: O(1)
// Approach: We can use a combination of digit dynamic programming (DP) and precomputation to count the number of "fancy" numbers in a given range. A "fancy" number is defined as a number whose digits are either strictly increasing or strictly decreasing. We first precompute all valid "good" sums (the sum of the digits of a number) and store them in a boolean array. Then, we generate all strictly increasing and strictly decreasing numbers using bitmasking to grab all possible subsets of digits. We store these numbers in a set to avoid double-counting. Finally, we use digit DP to count the numbers with a "good" digit sum in the given range and add the count of precomputed exceptions to get the final result.
class Solution
{
private:
    bool good_sum[200];
    set<long long> extra_good_nums;
    long long memo[20][200];

    // Standard Digit DP to count numbers with a "good" digit sum
    long long dfs(const string &R, int pos, int sum, bool is_less)
    {
        if (pos == R.length())
        {
            return good_sum[sum] ? 1 : 0;
        }

        // Return memoized result if we are no longer bounded by the prefix of R
        if (is_less && memo[R.length() - pos][sum] != -1)
        {
            return memo[R.length() - pos][sum];
        }

        long long res = 0;
        int limit = is_less ? 9 : (R[pos] - '0');

        for (int d = 0; d <= limit; ++d)
        {
            res += dfs(R, pos + 1, sum + d, is_less || (d < limit));
        }

        if (is_less)
        {
            memo[R.length() - pos][sum] = res;
        }
        return res;
    }

    long long solveDP(long long X)
    {
        if (X < 0)
            return 0;
        return dfs(to_string(X), 0, 0, false);
    }

public:
    Solution()
    {
        memset(memo, -1, sizeof(memo));

        // 1. Precompute all valid "good" sums (maximum possible sum is < 200)
        for (int i = 0; i < 200; ++i)
        {
            string s = to_string(i);
            bool inc = true, dec = true;
            for (int j = 1; j < s.length(); ++j)
            {
                if (s[j] <= s[j - 1])
                    inc = false;
                if (s[j] >= s[j - 1])
                    dec = false;
            }
            good_sum[i] = (inc || dec);
        }

        // 2. Generate all strictly increasing numbers
        // We use bitmasking to grab all possible subsets of {1, 2, ..., 9}
        for (int mask = 1; mask < (1 << 9); ++mask)
        {
            long long val = 0;
            int sum = 0;
            for (int d = 1; d <= 9; ++d)
            {
                if (mask & (1 << (d - 1)))
                {
                    val = val * 10 + d;
                    sum += d;
                }
            }
            // Only save it if the sum ISN'T good (to prevent double-counting
            // with DP)
            if (!good_sum[sum])
            {
                extra_good_nums.insert(val);
            }
        }

        // 3. Generate all strictly decreasing numbers
        // We use bitmasking to grab all possible subsets of {9, 8, ..., 0}
        for (int mask = 1; mask < (1 << 10); ++mask)
        {
            long long val = 0;
            int sum = 0;
            for (int d = 9; d >= 0; --d)
            {
                if (mask & (1 << d))
                {
                    val = val * 10 + d;
                    sum += d;
                }
            }
            if (!good_sum[sum])
            {
                extra_good_nums.insert(val);
            }
        }
    }
    long long countFancy(long long l, long long r)
    {
        // Find all numbers with a "good" sum in the range using Prefix
        // subtraction
        long long ans = solveDP(r) - solveDP(l - 1);

        // Manually check our precomputed exceptions
        for (long long x : extra_good_nums)
        {
            if (x >= l && x <= r)
            {
                ans++;
            }
        }

        return ans;
    }
};
