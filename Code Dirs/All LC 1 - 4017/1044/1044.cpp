// Link: https://leetcode.com/problems/longest-duplicate-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        int lo = 1, hi = n - 1;
        string best = "";
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            string found = search(s, mid);
            if (!found.empty()) {
                best = found;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return best;
    }

private:
    string search(const string& s, int len) {
        if (len == 0) return "";
        int n = s.size();
        const long long MOD = 1e18 + 9;
        const long long BASE = 26;
        long long h = 0, pow = 1;
        for (int i = 0; i < len; i++) {
            h = (h * BASE + (s[i] - 'a')) % MOD;
            if (i > 0) pow = (pow * BASE) % MOD;
        }
        unordered_map<long long, vector<int>> seen;
        seen[h].push_back(0);
        for (int i = 1; i + len <= n; i++) {
            h = ((h - (long long)(s[i-1]-'a') * pow % MOD + MOD) % MOD * BASE + (s[i+len-1]-'a')) % MOD;
            if (seen.count(h)) {
                for (int j : seen[h]) {
                    if (s.compare(j, len, s, i, len) == 0) return s.substr(i, len);
                }
            }
            seen[h].push_back(i);
        }
        return "";
    }
};
