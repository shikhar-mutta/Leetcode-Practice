// Link: https://leetcode.com/problems/palindromic-substrings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(1)
// Approach: expand around each center (odd and even length) counting valid palindromic expansions.
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for (int c = 0; c < n; c++) {
            for (int l = c, r = c; l >= 0 && r < n && s[l] == s[r]; l--, r++) count++;
            for (int l = c, r = c+1; l >= 0 && r < n && s[l] == s[r]; l--, r++) count++;
        }
        return count;
    }
};
