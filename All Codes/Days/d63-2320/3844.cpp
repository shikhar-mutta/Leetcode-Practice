// Link: https://leetcode.com/problems/longest-almost-palindromic-substring/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(1)
// Approach: for every center (odd single-char, even double-char, even
// double-char treated as an empty core when its two chars mismatch),
// expand outward while characters match to find the maximal pure
// palindrome core. Beyond that core, try using the one allowed deletion
// on the very next left or right character, then keep expanding in
// lockstep — this correctly captures both "delete a boundary character"
// and "delete a character strictly inside" cases, since after the single
// skip the remaining comparison must match perfectly like a normal
// palindrome expansion.
class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.size();
        int ans = 0;

        auto process = [&](int l, int r) {
            while (l-1 >= 0 && r+1 < n && s[l-1] == s[r+1]) { l--; r++; }
            ans = max(ans, r - l + 1);

            if (l-1 >= 0) {
                int a = l-2, b = r+1;
                while (a >= 0 && b < n && s[a] == s[b]) { a--; b++; }
                ans = max(ans, b - a - 1);
            }
            if (r+1 < n) {
                int a = l-1, b = r+2;
                while (a >= 0 && b < n && s[a] == s[b]) { a--; b++; }
                ans = max(ans, b - a - 1);
            }
        };

        for (int i = 0; i < n; i++) process(i, i);
        for (int i = 0; i + 1 < n; i++) process(i+1, i);

        return ans;
    }
};
