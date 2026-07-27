// Link: https://leetcode.com/problems/subsequence-after-one-replacement/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m) SC: O(n)
// Approach: since the replaced character can become anything, it just
// needs to "consume" at least one character of t without needing to
// match it specifically. Compute pre[i] = leftmost position in t after
// greedily matching s[0..i-1] as a subsequence (INF if impossible), and
// suf[i] = rightmost starting position in t after greedily matching
// s[i..] from the right (-1 if impossible). s can become a subsequence
// of t via at most one replacement iff either s is already a subsequence
// (pre[n] <= m), or some split index i has pre[i] < suf[i+1] (a genuine
// gap to absorb the replaced character).
class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        const int INF = m + 1;

        vector<int> pre(n + 1);
        pre[0] = 0;
        int j = 0;
        bool broken = false;
        for (int i = 0; i < n; i++) {
            if (broken) { pre[i+1] = INF; continue; }
            while (j < m && t[j] != s[i]) j++;
            if (j < m) { j++; pre[i+1] = j; }
            else { broken = true; pre[i+1] = INF; }
        }
        if (pre[n] <= m) return true;

        vector<int> suf(n + 1);
        suf[n] = m;
        j = m - 1;
        broken = false;
        for (int i = n - 1; i >= 0; i--) {
            if (broken) { suf[i] = -1; continue; }
            while (j >= 0 && t[j] != s[i]) j--;
            if (j >= 0) { suf[i] = j; j--; }
            else { broken = true; suf[i] = -1; }
        }

        for (int i = 0; i < n; i++) {
            if (pre[i] < suf[i+1]) return true;
        }
        return false;
    }
};
