// Link: https://leetcode.com/problems/minimize-array-sum-using-divisible-replacements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(maxVal log maxVal) SC: O(maxVal)
//  Approach: replacing a with b (b|a) only ever moves around values
//  already present in nums — no new distinct value is ever created, and
//  by transitivity of divisibility, chaining through an intermediate
//  value never beats a direct divisor already in the set. So each x's
//  best achievable value is simply the smallest distinct value in nums
//  that divides x. Find this via a sieve over the distinct values.
class Solution
{
public:
    long long minArraySum(vector<int> &nums)
    {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> present(maxVal + 1, false);
        for (int x : nums)
            present[x] = true;

        vector<int> minDiv(maxVal + 1, 0);
        for (int v = 1; v <= maxVal; v++)
        {
            if (!present[v])
                continue;
            for (int m = v; m <= maxVal; m += v)
            {
                if (present[m] && minDiv[m] == 0)
                    minDiv[m] = v;
            }
        }

        long long sum = 0;
        for (int x : nums)
            sum += minDiv[x];
        return sum;
    }
};
