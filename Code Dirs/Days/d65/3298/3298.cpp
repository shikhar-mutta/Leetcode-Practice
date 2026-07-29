// Link: https://leetcode.com/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(1)
// Approach: two-pointer. For each right endpoint, shrink left as far as possible while
// word1[left..right] still contains word2's character multiset; every smaller left (further
// left) also stays valid, so all `left+1` starting positions from 0..left count as valid
// substrings ending at right.
class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int need[26] = {};
        for (char c : word2) need[c-'a']++;
        int required = 0;
        for (int i = 0; i < 26; i++) if (need[i] > 0) required++;

        int window[26] = {};
        int satisfied = 0;
        int left = 0;
        long long ans = 0;
        int n = word1.size();

        for (int right = 0; right < n; right++) {
            int c = word1[right] - 'a';
            window[c]++;
            if (window[c] == need[c]) satisfied++;

            if (satisfied == required) {
                while (left <= right) {
                    int lc = word1[left] - 'a';
                    if (window[lc] - 1 < need[lc]) break; // removing would violate this char's requirement
                    window[lc]--;
                    left++;
                }
                ans += left + 1;
            }
        }
        return ans;
    }
};
