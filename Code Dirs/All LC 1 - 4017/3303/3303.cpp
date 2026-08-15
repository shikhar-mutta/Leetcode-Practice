// Link: https://leetcode.com/problems/find-the-occurrence-of-first-almost-equal-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> zFunction(const string& t) {
        int n = t.size();
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i < r) z[i] = min(r - i, z[i - l]);
            while (i + z[i] < n && t[z[i]] == t[i + z[i]]) z[i]++;
            if (i + z[i] > r) { l = i; r = i + z[i]; }
        }
        return z;
    }

    int minStartingIndex(string s, string pattern) {
        int n = s.size(), m = pattern.size();

        // prefixMatch[i] = longest common prefix of pattern and s[i:]
        vector<int> prefixMatch(n, 0);
        {
            string t = pattern + '\x01' + s;
            vector<int> z = zFunction(t);
            for (int i = 0; i < n; i++) prefixMatch[i] = z[m + 1 + i];
        }

        // suffixMatch[i] = longest common suffix of pattern and s[..i] (ending at i)
        vector<int> suffixMatch(n, 0);
        {
            string revPattern(pattern.rbegin(), pattern.rend());
            string revS(s.rbegin(), s.rend());
            string t = revPattern + '\x01' + revS;
            vector<int> z = zFunction(t);
            for (int i = 0; i < n; i++) {
                int revIdx = n - 1 - i; // position in revS
                suffixMatch[i] = z[m + 1 + revIdx];
            }
        }

        for (int i = 0; i + m <= n; i++) {
            int L = prefixMatch[i];
            if (L >= m) return i;
            int R = suffixMatch[i + m - 1];
            if (L + R >= m - 1) return i;
        }
        return -1;
    }
};
