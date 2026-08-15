// Link: https://leetcode.com/problems/shortest-matching-substring/description/

#include <bits/stdc++.h>
using namespace std;

const int INF3455 = 1E9;

struct KMP3455 {
    int n;
    string s;
    vector<int> lps;

    KMP3455(string& s) {
        this->s = s;
        n = s.size();
        lps.assign(n, 0);
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && s[i] != s[j]) {
                j = lps[j - 1];
            }
            j += s[i] == s[j];
            lps[i] = j;
        }
    }

    vector<int> getPos(string& text) {
        vector<int> res;
        int m = text.size();
        for (int i = 0, j = 0; i < m; i++) {
            while (j > 0 && text[i] != s[j]) {
                j = lps[j - 1];
            }
            j += text[i] == s[j];
            if (j == n) {
                res.push_back(i - n + 1);
                j = lps[j - 1];
            }
        }
        return res;
    }
};

class Solution {
public:
    int shortestMatchingSubstring(string s, string p, int ans = INF3455) {
        if (p == "**") return 0;
        int n = s.size(), m = p.size();
        int i1 = p.find('*'), i2 = p.find('*', i1 + 1);
        string lo = p.substr(0, i1);
        string mi = p.substr(i1 + 1, i2 - i1 - 1);
        string hi = p.substr(i2 + 1);
        KMP3455 kmp1(lo), kmp2(mi), kmp3(hi);
        int x1 = lo.size(), x2 = mi.size(), x3 = hi.size();
        if (x1 && x2 && x3) {
            int j = 0, k = 0;
            vector<vector<int>> pos(3);
            pos[0] = kmp1.getPos(s);
            pos[1] = kmp2.getPos(s);
            pos[2] = kmp3.getPos(s);
            int m1 = pos[1].size(), m2 = pos[2].size();
            for (auto& i : pos[0]) {
                while (j < m1 && pos[1][j] < i + x1) {
                    j++;
                }
                if (j == m1) break;
                while (k < m2 && pos[2][k] < pos[1][j] + x2) {
                    k++;
                }
                if (k == m2) break;
                ans = min(ans, pos[2][k] + x3 - i);
            }
            if (ans != INF3455) {
                return ans;
            }
        } else if ((x1 && x2) || (x1 && x3) || (x2 && x3)) {
            int top = 0, j = 0;
            vector<vector<int>> pos(2);
            int fst = x1 ? x1 : x2 ? x2
                                   : x3;
            int lst = x3 ? x3 : x2 ? x2
                                   : x1;
            if (x1) pos[top++] = kmp1.getPos(s);
            if (x2) pos[top++] = kmp2.getPos(s);
            if (x3) pos[top++] = kmp3.getPos(s);
            int m1 = pos[1].size();
            for (auto& i : pos[0]) {
                while (j < m1 && pos[1][j] < i + fst) {
                    j++;
                }
                if (j == m1) break;
                ans = min(ans, pos[1][j] + lst - i);
            }
            if (ans != INF3455) {
                return ans;
            }
        } else if (x1 && !kmp1.getPos(s).empty()) {
            return x1;
        } else if (x2 && !kmp2.getPos(s).empty()) {
            return x2;
        } else if (x3 && !kmp3.getPos(s).empty()) {
            return x3;
        }
        return -1;
    }
};
