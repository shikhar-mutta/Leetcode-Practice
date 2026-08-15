// Link: https://leetcode.com/problems/longest-repeating-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.size();
        int lo = 0, hi = n - 1;
        int best = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (mid > 0 && hasDup(s, mid)) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return best;
    }

private:
    bool hasDup(const string& s, int len) {
        int n = s.size();
        const long long MOD = 1e18 + 9;
        const long long BASE = 26;
        long long h = 0, pw = 1;
        for (int i = 0; i < len; i++) {
            h = (h * BASE + (s[i]-'a')) % MOD;
            if (i > 0) pw = (pw * BASE) % MOD;
        }
        unordered_set<long long> seen;
        seen.insert(h);
        for (int i = 1; i + len <= n; i++) {
            h = ((h - (long long)(s[i-1]-'a') * pw % MOD + MOD) % MOD * BASE + (s[i+len-1]-'a')) % MOD;
            if (seen.count(h)) return true;
            seen.insert(h);
        }
        return false;
    }
};
