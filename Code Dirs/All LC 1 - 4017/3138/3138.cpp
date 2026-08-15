// Link: https://leetcode.com/problems/minimum-length-of-anagram-concatenation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    array<int,26> countOf(const string& s, int l, int r) {
        array<int,26> f{};
        for (int i = l; i < r; i++) f[s[i]-'a']++;
        return f;
    }

    int minAnagramLength(string s) {
        int n = s.size();
        for (int L = 1; L <= n; L++) {
            if (n % L != 0) continue;
            auto base = countOf(s, 0, L);
            bool ok = true;
            for (int i = L; i < n && ok; i += L) {
                auto cur = countOf(s, i, i + L);
                if (cur != base) ok = false;
            }
            if (ok) return L;
        }
        return n;
    }
};
