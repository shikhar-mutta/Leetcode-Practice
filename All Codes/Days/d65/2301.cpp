// Link: https://leetcode.com/problems/match-substring-after-replacement/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m) where n = s.size(), m = sub.size(), SC: O(1)
// Approach: Bitap algorithm (shift-and) — maintain a bitset of length m, where the j-th bit is set if the first j characters of sub can be matched with a suffix of the current prefix of s. For each character c in s, we shift the bitset left by 1, set the 0-th bit, and AND it with a mask for c that has the j-th bit set if sub[j] can be replaced by c. If the (m-1)-th bit is ever set, we have found a match.
class Solution
{
    static constexpr int MAXN = 5000;

    bool bitapSearch(const string &s, int m,
                     const array<bitset<MAXN>, 128> &mask)
    {
        bitset<MAXN> dp;

        for (unsigned char c : s)
        {
            dp <<= 1;
            dp.set(0);
            dp &= mask[c];

            if (dp.test(m - 1))
            {
                return true;
            }
        }

        return false;
    }

public:
    bool matchReplacement(string s, string sub,
                          vector<vector<char>> &mappings)
    {
        bool can[128][128] = {};

        for (int c = 0; c < 128; c++)
        {
            can[c][c] = true;
        }

        for (auto &mp : mappings)
        {
            unsigned char oldChar = mp[0];
            unsigned char newChar = mp[1];
            can[oldChar][newChar] = true;
        }

        int m = sub.size();

        array<bitset<MAXN>, 128> mask{};

        for (int j = 0; j < m; j++)
        {
            unsigned char from = sub[j];

            for (int c = 0; c < 128; c++)
            {
                if (can[from][c])
                {
                    mask[c].set(j);
                }
            }
        }

        return bitapSearch(s, m, mask);
    }
};
