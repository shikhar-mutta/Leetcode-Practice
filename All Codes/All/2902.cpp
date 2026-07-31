// Link: https://leetcode.com/problems/count-of-sub-multisets-with-bounded-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N * R), SC: O(R)
// Approach: We can use a frequency array to keep track of the number of occurrences of each number in the input array. We then use dynamic programming to count the number of sub-multisets that have a sum within the given bounds [l, r]. The memo array is used to store the count of sub-multisets for each possible sum, and we update it based on the frequency of each number. Finally, we return the total count of valid sub-multisets modulo 1e9 + 7.
class Solution
{
public:
    int countSubMultisets(const vector<int> &nums, int l, int r)
    {
        int cnt[20001] = {};
        int memo[20001] = {};
        const int mod = 1000000007;
        for (int n : nums)
        {
            ++cnt[n];
        }
        fill_n(memo, cnt[1] + 1, 1);
        for (int n = 2, total = cnt[1]; n <= r; ++n)
        {
            if (!cnt[n])
            {
                continue;
            }
            int top = (cnt[n] + 1) * n;
            total += n * cnt[n];
            for (int i = n, ii = min(total, r); i <= ii; ++i)
            {
                memo[i] = (memo[i] + memo[i - n]) % mod;
            }
            for (int i = min(total, r); i >= top; --i)
            {
                memo[i] = (mod + memo[i] - memo[i - top]) % mod;
            }
        }
        return accumulate(memo + l, memo + r + 1, 0LL) * (cnt[0] + 1) % mod;
    }
};
