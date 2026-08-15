// Link: https://leetcode.com/problems/tallest-billboard/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int,int> dp;
        dp[0] = 0;
        for (int r : rods) {
            unordered_map<int,int> next = dp;
            for (auto& [diff, tall] : dp) {
                int d1 = diff + r, t1 = tall + r;
                if (!next.count(d1) || next[d1] < t1) next[d1] = t1;

                int d2 = diff - r, t2 = tall;
                if (d2 < 0) { t2 = tall - diff + r; d2 = -d2; }
                if (!next.count(d2) || next[d2] < t2) next[d2] = t2;
            }
            dp = next;
        }
        return dp[0];
    }
};
