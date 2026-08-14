// Link: https://leetcode.com/problems/plates-between-candles/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + (s[i] == '*');

        vector<int> nextCandle(n, -1);
        int last = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '|') last = i;
            nextCandle[i] = last;
        }
        vector<int> prevCandle(n, -1);
        last = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|') last = i;
            prevCandle[i] = last;
        }

        vector<int> res;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int lc = nextCandle[l];
            int rc = prevCandle[r];
            if (lc != -1 && rc != -1 && lc < rc) {
                res.push_back(prefix[rc] - prefix[lc]);
            } else {
                res.push_back(0);
            }
        }
        return res;
    }
};
