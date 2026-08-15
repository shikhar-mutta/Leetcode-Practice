// Link: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 26)  SC: O(n) recursion
// Approach: divide and conquer - any char occurring fewer than k times can't
// be part of a valid substring, so split on it and recurse on each side
class Solution {
    int solve(const string& s, int lo, int hi, int k) {
        if (hi - lo < k) return 0;
        int count[26] = {0};
        for (int i = lo; i < hi; i++) count[s[i] - 'a']++;

        for (int i = lo; i < hi; i++) {
            if (count[s[i] - 'a'] > 0 && count[s[i] - 'a'] < k) {
                int j = i;
                while (j < hi && count[s[j] - 'a'] < k) j++;
                int left = solve(s, lo, i, k);
                int right = solve(s, j, hi, k);
                return max(left, right);
            }
        }
        return hi - lo;
    }

public:
    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size(), k);
    }
};
