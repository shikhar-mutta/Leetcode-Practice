// Link: https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_set<long long> powersOf5;

    bool isBeautiful(string &sub) {
        if (sub[0] == '0') return false;
        long long val = 0;
        for (char c : sub) val = val * 2 + (c - '0');
        return powersOf5.count(val) > 0;
    }

    int dp(string &s, int pos, vector<int> &memo) {
        int n = s.size();
        if (pos == n) return 0;
        if (memo[pos] != -2) return memo[pos];

        int best = INT_MAX;
        for (int end = pos + 1; end <= n; end++) {
            string sub = s.substr(pos, end - pos);
            if (isBeautiful(sub)) {
                int rest = dp(s, end, memo);
                if (rest != INT_MAX) best = min(best, 1 + rest);
            }
        }
        return memo[pos] = best;
    }

public:
    int minimumBeautifulSubstrings(string s) {
        long long p = 1;
        for (int i = 0; i < 20; i++) { powersOf5.insert(p); p *= 5; }

        vector<int> memo(s.size(), -2);
        int res = dp(s, 0, memo);
        return res == INT_MAX ? -1 : res;
    }
};
