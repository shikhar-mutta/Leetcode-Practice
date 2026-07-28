// Link: https://leetcode.com/problems/longest-palindrome-after-substring-concatenation-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*(m+n)) SC: O(m*n)
// Approach: reverse t. g1[i]/g2[j] = length of the longest palindromic
// substring starting at index i of s / index j of reversed-t (via center
// expansion). f[i][j] = length of the matching run ending at s[i-1] and
// reversedT[j-1] (grows the palindrome shell from both ends outward,
// since matching a char of s against a char of reversed t means s's char
// mirrors t's char from the far end). Each matched shell of length
// f[i][j] can absorb an extra whole palindrome right after it in s
// (g1[i]) or in reversed t (g2[j]) as its center; take the best over all
// (i,j), plus the baseline of the best standalone palindrome in s or t.
class Solution {
    vector<int> longestPalinStartingAt(const string& str) {
        int n = str.size();
        vector<int> g(n, 0);
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && str[l] == str[r]) {
                g[l] = max(g[l], r - l + 1);
                l--; r++;
            }
        };
        for (int i = 0; i < n; i++) { expand(i, i); expand(i, i + 1); }
        return g;
    }
public:
    int longestPalindrome(string s, string t) {
        int m = s.size(), n = t.size();
        string tr(t.rbegin(), t.rend());
        vector<int> g1 = longestPalinStartingAt(s);
        vector<int> g2 = longestPalinStartingAt(tr);

        int ans = 0;
        for (int v : g1) ans = max(ans, v);
        for (int v : g2) ans = max(ans, v);

        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == tr[j-1]) {
                    f[i][j] = f[i-1][j-1] + 1;
                    ans = max(ans, f[i][j] * 2 + (i >= m ? 0 : g1[i]));
                    ans = max(ans, f[i][j] * 2 + (j >= n ? 0 : g2[j]));
                }
            }
        }
        return ans;
    }
};
