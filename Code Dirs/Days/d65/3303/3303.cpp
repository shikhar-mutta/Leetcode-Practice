// Link: https://leetcode.com/problems/find-the-occurrence-of-first-almost-equal-substring/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N + M), SC: O(N + M)
// Approach: an "almost equal" match at start i needs Hamming distance <= 1 between
// s[i..i+m-1] and pattern. Precompute prefixMatch[i] = LCP(s[i:], pattern) via Z-function on
// pattern+'#'+s, and suffixMatch[i] = length of matching suffix ending at i via Z-function on
// reverse(pattern)+'#'+reverse(s). A window starting at i works if prefixMatch[i] alone covers
// the whole pattern, or prefixMatch[i] + suffixMatch[i+m-1] >= m-1 (everything except a single
// middle position matches from both ends).
class Solution {
public:
    vector<int> zFunction(const string& s) {
        int n = s.size();
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i < r) z[i] = min(r - i, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
            if (i + z[i] > r) { l = i; r = i + z[i]; }
        }
        return z;
    }

    int minStartingIndex(string s, string pattern) {
        int n = s.size(), m = pattern.size();
        if (m > n) return -1;

        string combo1 = pattern + "#" + s;
        vector<int> z1 = zFunction(combo1);
        vector<int> prefixMatch(n, 0);
        for (int i = 0; i < n; i++) prefixMatch[i] = z1[m + 1 + i];

        string revPattern = pattern; reverse(revPattern.begin(), revPattern.end());
        string revS = s; reverse(revS.begin(), revS.end());
        string combo2 = revPattern + "#" + revS;
        vector<int> z2 = zFunction(combo2);
        vector<int> suffixMatch(n, 0); // suffixMatch[i] = match length ending at i (0-indexed) in s
        for (int i = 0; i < n; i++) {
            int revIdx = n - 1 - i; // position of s[i] in revS
            suffixMatch[i] = z2[m + 1 + revIdx];
        }

        for (int i = 0; i + m <= n; i++) {
            if (prefixMatch[i] >= m) return i;
            int suf = suffixMatch[i + m - 1];
            if (prefixMatch[i] + suf >= m - 1) return i;
        }
        return -1;
    }
};
