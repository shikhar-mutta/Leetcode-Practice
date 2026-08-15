// Link: https://leetcode.com/problems/count-substrings-with-k-frequency-characters-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: Two-pointer sliding window: shrink from the left whenever the
// current character's count reaches k (since any substring including that
// point would satisfy the >=k condition). For each right endpoint, every
// start position before the shrunk left boundary gives a valid substring,
// so add l (the count of such valid starts) to the answer.
class Solution {
public:
    long long numberOfSubstrings(string s, int k) {
        int cnt[26] = {};
        int l = 0;
        long long ans = 0;

        for (char c : s) {
            ++cnt[c - 'a'];
            while (cnt[c - 'a'] >= k) {
                --cnt[s[l] - 'a'];
                ++l;
            }
            ans += l;
        }

        return ans;
    }
};
