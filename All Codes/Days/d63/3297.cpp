// Link: https://leetcode.com/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(|s1| + 26), SC: O(1)
// Approach: Two-pointer sliding window tracking how many still-needed
// character copies (k, starting at |s2|) remain unmatched. Once the window
// [start, i] satisfies every letter count of s2 (k==0), every further right
// extension stays valid too, so add (s1.length()-i) for this start, then
// shrink from the left until the window is no longer fully satisfying.
class Solution {
public:
    long long validSubstringCount(string s1, string s2) {
        vector<int> v(26, 0);
        for (char c : s2) {
            v[c - 'a']++;
        }

        vector<int> cnt(26, 0);
        int start = 0, k = s2.length();
        long long c = 0;

        for (int i = 0; i < s1.length(); i++) {
            char curr = s1[i];

            if (v[curr - 'a'] > 0) {
                if (cnt[curr - 'a'] < v[curr - 'a']) {
                    k--;
                }
            }

            cnt[curr - 'a']++;

            while (k == 0) {
                c += s1.length() - i;

                char pre = s1[start];
                cnt[pre - 'a']--;

                if (v[pre - 'a'] > 0 and cnt[pre - 'a'] < v[pre - 'a']) {
                    k++;
                }

                start++;
            }
        }

        return c;
    }
};
