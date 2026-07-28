// Link: https://leetcode.com/problems/stickers-to-spell-word/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(2^m * n * L)  SC: O(2^m)
// Approach: bitmask DP over which target letters are covered so far.
// dp[mask] = min stickers to cover that mask. From each state, try
// applying every sticker (greedily using all useful letters it offers)
// to reach a superset mask, memoizing results.
class Solution
{
public:
    int n, m;
    vector<long> dp;
    long recurr(vector<int> fre[], string &target, int mask = 0)
    {
        if (mask == (1 << m) - 1)
            return 0;

        if (dp[mask] != -1)
            return dp[mask];
        int ind = -1;
        for (int i = 0, k = 1; i < m; i++, k <<= 1)
        {
            if ((mask & k) == 0)
            {
                ind = i;
                break;
            }
        }

        long ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (fre[i][target[ind] - 'a'])
            {
                int newMask = mask;
                for (int j = ind, k = (1 << j); j < target.size(); j++, k <<= 1)
                {
                    if (fre[i][target[j] - 'a'] != 0 && (newMask & k) == 0)
                    {
                        newMask |= k;
                        fre[i][target[j] - 'a']--;
                    }
                }

                for (int j = 0, k = 1; j < target.size(); j++, k <<= 1)
                {
                    if ((mask ^ newMask) & k)
                    {
                        fre[i][target[j] - 'a']++;
                    }
                }
                ans = min(ans, 1 + recurr(fre, target, newMask));
            }
        }

        return dp[mask] = ans;
    }
    int minStickers(vector<string> &stickers, string target)
    {
        n = stickers.size();
        m = target.size();
        dp.assign(1 << m, -1);

        vector<int> fre[n];
        for (int i = 0; i < n; i++)
        {
            fre[i].assign(26, 0);
            for (auto &c : stickers[i])
            {
                fre[i][c - 'a']++;
            }
        }
        long ans = recurr(fre, target);
        return ans >= INT_MAX ? -1 : ans;
    }
};