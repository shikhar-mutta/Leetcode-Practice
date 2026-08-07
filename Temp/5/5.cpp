// Link: https://leetcode.com/problems/longest-palindromic-substring/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(1)
// Approach: expand around every center (odd and even length), track best window
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int bestL = 0, bestLen = 0;
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) { l--; r++; }
            int len = r - l - 1;
            if (len > bestLen) { bestLen = len; bestL = l + 1; }
        };
        for (int i = 0; i < n; i++) {
            expand(i, i);
            expand(i, i + 1);
        }
        return s.substr(bestL, bestLen);
    }
};
