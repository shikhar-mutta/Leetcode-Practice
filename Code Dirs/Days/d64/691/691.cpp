// Link: https://leetcode.com/problems/stickers-to-spell-word/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(2^m * n * L)  SC: O(2^m)
// Approach: bitmask DP over which target letters are covered so far.
// dp[mask] = min stickers to cover that mask. From each state, try
// applying every sticker (greedily using all useful letters it offers)
// to reach a superset mask, memoizing results.
class Solution {
    unordered_map<int, int> memo;
    vector<array<int,26>> stickerCount;
    string target;
public:
    int minStickers(vector<string>& stickers, string t) {
        target = t;
        for (auto& s : stickers) {
            array<int,26> cnt{};
            for (char c : s) cnt[c - 'a']++;
            stickerCount.push_back(cnt);
        }
        int fullMask = (1 << target.size()) - 1;
        memo[0] = 0;
        int res = dfs(fullMask);
        return res == INT_MAX ? -1 : res;
    }
    int dfs(int mask) {
        if (mask == 0) return 0;
        if (memo.count(mask)) return memo[mask];
        int best = INT_MAX;
        for (auto& cnt : stickerCount) {
            array<int,26> avail = cnt;
            int newMask = mask;
            for (int i = 0; i < (int)target.size(); i++) {
                if (!(mask & (1 << i))) continue;
                int c = target[i] - 'a';
                if (avail[c] > 0) {
                    avail[c]--;
                    newMask &= ~(1 << i);
                }
            }
            if (newMask == mask) continue; // sticker didn't help
            int sub = dfs(newMask);
            if (sub != INT_MAX) best = min(best, sub + 1);
        }
        memo[mask] = best;
        return best;
    }
};
