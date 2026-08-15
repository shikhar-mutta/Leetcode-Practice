// Link: https://leetcode.com/problems/longest-palindrome-after-substring-concatenation-i/description/

#include <bits/stdc++.h>
using namespace std;

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
