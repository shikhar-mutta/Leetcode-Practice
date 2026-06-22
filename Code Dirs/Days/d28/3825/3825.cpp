// Link: https://leetcode.com/problems/longest-strictly-increasing-subsequence-with-non-zero-bitwise-and/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public: // 2:28
    int longestSubsequence(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < 30; i++)
        {
            vector<int> stk;  // monotonic increasing stack
            int bit = 1 << i; // check the i-th bit
            for (auto &u : nums)
            {
                if (u & bit) // if the i-th bit is set, then bitwise AND is non-zero
                {
                    if (stk.empty() || stk.back() < u)
                        stk.push_back(u);
                    else
                        *lower_bound(stk.begin(), stk.end(), u) = u;
                }
            }
            res = max(res, (int)stk.size()); // update the result with the size of the current stack
        }
        return res;
    }
};