// Link: https://leetcode.com/problems/frequencies-of-shortest-supersequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n * n)  SC: O(2^n)
// Approach: Use bitmask DP to find the maximum number of letters that can be included in a supersequence without violating the constraints given by the words. Each letter is represented as a bit in a mask, and we iterate through all possible combinations of letters, checking if adding a new letter would violate any constraints. Finally, we collect all masks that achieve the maximum number of letters and convert them back to the required frequency format for the answer.
class Solution
{
public:
    static auto solve(int n, array<uint16_t, 16> xy)
    {
        vector<char> dp(1 << n);
        dp[0] = 1;

        int best = 0;
        for (int mask = 0; mask < (1 << n); mask++)
        {
            if (!dp[mask])
                continue;
            best = max(best, (int)__builtin_popcount(mask));
            for (int add = 0; add < n; ++add)
            {
                int new_mask = mask | (1 << add);
                if (xy[add] & new_mask)
                    continue;
                dp[new_mask] = true;
            }
        }

        vector<bitset<16>> ans;
        for (int mask = 0; mask < (1 << n); mask++)
        {
            if (dp[mask] && __builtin_popcount(mask) == best)
            {
                ans.emplace_back(mask);
            }
        }
        return ans;
    }

    vector<vector<int>> supersequences(vector<string> &words)
    {
        array<int, 26> to_idx{}, to_char{};
        for (const string &w : words)
        {
            for (char c : w)
            {
                to_idx[c - 'a'] = 1;
            }
        }
        int n = 0;
        for (int c = 0; c < 26; ++c)
        {
            int new_n = n + to_idx[c];
            to_idx[c] = n;
            to_char[n] = c;
            n = new_n;
        }
        array<uint16_t, 16> xy{};
        for (const string &w : words)
        {
            int x = to_idx[w[0] - 'a'];
            int y = to_idx[w[1] - 'a'];
            xy[x] |= 1 << y;
        }

        vector<bitset<16>> singles = solve(n, xy);
        vector<vector<int>> ans(singles.size(), vector<int>(26, 0));
        for (int i = 0; i < singles.size(); ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ans[i][to_char[j]] = 2 - static_cast<int>(singles[i].test(j));
            }
        }
        return ans;
    }
};
