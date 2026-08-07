// Link: https://leetcode.com/problems/stickers-to-spell-word/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n * m * 26) SC: O(2^n)
// Approach: bitmask DP over which target letters are covered; dp[mask] = min stickers to cover that mask. For each mask, try applying each sticker to compute the resulting covered mask and transition.
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size();
        int full = (1 << n) - 1;
        vector<int> dp(1 << n, INT_MAX);
        dp[0] = 0;
        vector<array<int,26>> stickerCount;
        for (auto& s : stickers) {
            array<int,26> cnt{};
            for (char c : s) cnt[c-'a']++;
            stickerCount.push_back(cnt);
        }
        for (int mask = 0; mask <= full; mask++) {
            if (dp[mask] == INT_MAX) continue;
            for (auto& cnt : stickerCount) {
                array<int,26> avail = cnt;
                int nmask = mask;
                for (int i = 0; i < n; i++) {
                    if (mask & (1<<i)) continue;
                    char c = target[i];
                    if (avail[c-'a'] > 0) { avail[c-'a']--; nmask |= (1<<i); }
                }
                if (dp[nmask] > dp[mask] + 1) dp[nmask] = dp[mask] + 1;
            }
        }
        return dp[full] == INT_MAX ? -1 : dp[full];
    }
};
