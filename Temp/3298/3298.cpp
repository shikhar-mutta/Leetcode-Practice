// Link: https://leetcode.com/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int need[26] = {0};
        for (char c : word2) need[c - 'a']++;
        int distinctNeeded = 0;
        for (int i = 0; i < 26; i++) if (need[i] > 0) distinctNeeded++;

        int window[26] = {0};
        int satisfied = 0;
        int n = word1.size();
        long long ans = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            int c = word1[right] - 'a';
            window[c]++;
            if (need[c] > 0 && window[c] == need[c]) satisfied++;

            while (satisfied == distinctNeeded) {
                int lc = word1[left] - 'a';
                window[lc]--;
                if (need[lc] > 0 && window[lc] == need[lc] - 1) satisfied--;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};
