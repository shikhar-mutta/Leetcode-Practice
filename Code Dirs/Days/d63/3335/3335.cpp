// Link: https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(26*t + n) SC: O(1)
// Approach: track count of each letter (26 buckets). Each transformation
// step shifts every letter's count to the next letter, except 'z' which
// splits its count into both 'a' and 'b'. Simulate t steps, sum counts mod 1e9+7.
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        long long cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;

        for (int step = 0; step < t; step++) {
            long long next[26] = {0};
            for (int i = 0; i < 25; i++) next[i + 1] = (next[i + 1] + cnt[i]) % MOD;
            next[0] = (next[0] + cnt[25]) % MOD;
            next[1] = (next[1] + cnt[25]) % MOD;
            memcpy(cnt, next, sizeof(cnt));
        }

        long long ans = 0;
        for (int i = 0; i < 26; i++) ans = (ans + cnt[i]) % MOD;
        return (int)ans;
    }
};
