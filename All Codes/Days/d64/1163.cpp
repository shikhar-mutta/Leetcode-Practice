// Link: https://leetcode.com/problems/last-substring-in-lexicographical-order/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n) amortized  SC: O(1)
// Approach: two-pointer scan (i = best candidate start, j = current
// challenger start), comparing character by character with an offset k.
// If s[i+k] < s[j+k], the challenger wins so far, advance i past the
// comparison; if greater, the challenger loses, advance j; if equal,
// keep comparing at k+1. Ties resolved by always keeping the
// lexicographically larger (or equal, favoring the earlier/kept) start.
class Solution {
public:
    string lastSubstring(string s) {
        int n = s.size();
        int i = 0, j = 1, k = 0;
        while (j + k < n) {
            char a = s[i + k], b = s[j + k];
            if (a == b) {
                k++;
            } else if (a < b) {
                i = max(i + k + 1, j);
                j = i + 1;
                k = 0;
            } else {
                j = j + k + 1;
                k = 0;
            }
        }
        return s.substr(i);
    }
};
