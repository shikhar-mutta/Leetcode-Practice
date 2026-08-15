// Link: https://leetcode.com/problems/minimum-window-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(|s|*|t|) SC: O(1)
// Approach: scan s left to right; whenever a full match of t as a subsequence completes at position end, walk backward from end matching t in reverse to find the tightest start for that window, then continue scanning from start+1 to look for a shorter window.
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int bestLen = INT_MAX, bestStart = -1;
        int i = 0;
        while (i < n) {
            int j = 0;
            int start = i;
            while (i < n && j < m) {
                if (s[i] == t[j]) j++;
                i++;
            }
            if (j < m) break; // no more full matches possible
            int end = i; // exclusive
            // walk backward to shrink
            int k = m-1;
            int p = end-1;
            while (k >= 0) {
                if (s[p] == t[k]) k--;
                p--;
            }
            p++; // start of tightest window
            if (end - p < bestLen) { bestLen = end - p; bestStart = p; }
            i = p + 1;
        }
        return bestStart == -1 ? "" : s.substr(bestStart, bestLen);
    }
};
