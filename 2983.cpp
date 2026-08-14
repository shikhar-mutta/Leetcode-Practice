// Link: https://leetcode.com/problems/palindrome-rearrangement-queries/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> charPrefix; // charPrefix[c][i] = count of char c in s[0..i)
    vector<int> mismatchPrefix;     // over left-half indices [0..n/2]

    array<int,26> rangeFreq(int l, int r) {
        array<int,26> res{};
        if (l > r) return res;
        for (int c = 0; c < 26; c++) res[c] = charPrefix[c][r+1] - charPrefix[c][l];
        return res;
    }

    int mismatchCount(int l, int r) {
        if (l > r) return 0;
        return mismatchPrefix[r+1] - mismatchPrefix[l];
    }

    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        n = s.size();
        charPrefix.assign(26, vector<int>(n+1, 0));
        for (int c = 0; c < 26; c++)
            for (int i = 0; i < n; i++)
                charPrefix[c][i+1] = charPrefix[c][i] + (s[i]-'a'==c ? 1 : 0);

        mismatchPrefix.assign(n/2 + 1, 0);
        for (int i = 0; i < n/2; i++)
            mismatchPrefix[i+1] = mismatchPrefix[i] + (s[i] != s[n-1-i] ? 1 : 0);

        vector<bool> ans;
        for (auto& q : queries) {
            int a = q[0], b = q[1], c = q[2], d = q[3];
            int lpLo = n-1-d, lpHi = n-1-c; // L' in left-half index space

            int ilo = max(a, lpLo), ihi = min(b, lpHi);
            bool hasIntersection = ilo <= ihi;

            // union of L=[a,b] and L'=[lpLo,lpHi]
            vector<pair<int,int>> merged;
            {
                vector<pair<int,int>> iv = {{a,b},{lpLo,lpHi}};
                sort(iv.begin(), iv.end());
                for (auto& p : iv) {
                    if (!merged.empty() && p.first <= merged.back().second + 1) {
                        merged.back().second = max(merged.back().second, p.second);
                    } else {
                        merged.push_back(p);
                    }
                }
            }
            // complement within [0, n/2)
            int mismatches = 0;
            int prev = 0;
            for (auto& [lo, hi] : merged) {
                mismatches += mismatchCount(prev, lo - 1);
                prev = hi + 1;
            }
            mismatches += mismatchCount(prev, n/2 - 1);

            // L \ L'
            array<int,26> D1{};
            if (!hasIntersection) {
                D1 = rangeFreq(n-1-b, n-1-a);
            } else {
                if (a <= ilo - 1) {
                    auto f = rangeFreq(n-1-(ilo-1), n-1-a);
                    for (int c2=0;c2<26;c2++) D1[c2]+=f[c2];
                }
                if (ihi + 1 <= b) {
                    auto f = rangeFreq(n-1-b, n-1-(ihi+1));
                    for (int c2=0;c2<26;c2++) D1[c2]+=f[c2];
                }
            }

            // L' \ L
            array<int,26> D2{};
            if (!hasIntersection) {
                D2 = rangeFreq(lpLo, lpHi);
            } else {
                if (lpLo <= ilo - 1) {
                    auto f = rangeFreq(lpLo, ilo-1);
                    for (int c2=0;c2<26;c2++) D2[c2]+=f[c2];
                }
                if (ihi + 1 <= lpHi) {
                    auto f = rangeFreq(ihi+1, lpHi);
                    for (int c2=0;c2<26;c2++) D2[c2]+=f[c2];
                }
            }

            auto freqL = rangeFreq(a, b);
            auto freqR = rangeFreq(c, d);

            bool ok = (mismatches == 0);
            if (ok) {
                for (int c2 = 0; c2 < 26; c2++) {
                    if (freqL[c2] < D1[c2] || freqR[c2] < D2[c2]) { ok = false; break; }
                    if (freqL[c2] - D1[c2] != freqR[c2] - D2[c2]) { ok = false; break; }
                }
            }
            ans.push_back(ok);
        }
        return ans;
    }
};
