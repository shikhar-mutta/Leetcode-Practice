// Link: https://leetcode.com/problems/unique-substrings-in-wraparound-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) (26 letters)
// Approach: track running consecutive-increasing length; for each char,
// maxLen[c] = longest such run ending in c (this counts all unique
// substrings ending in c, since shorter ones are subsumed); sum over all 26
class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int maxLen[26] = {0};
        int run = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (i > 0 && (s[i] - s[i-1] == 1 || s[i-1] - s[i] == 25)) run++;
            else run = 1;
            maxLen[s[i] - 'a'] = max(maxLen[s[i] - 'a'], run);
        }
        int total = 0;
        for (int i = 0; i < 26; i++) total += maxLen[i];
        return total;
    }
};
