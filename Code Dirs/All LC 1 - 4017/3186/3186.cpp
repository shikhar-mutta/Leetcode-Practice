// Link: https://leetcode.com/problems/maximum-total-damage-with-spell-casting/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, long long> cnt;
        for (int x : power) cnt[x]++;
        vector<int> vals;
        vector<long long> dmg;
        for (auto& [v, c] : cnt) { vals.push_back(v); dmg.push_back((long long)v * c); }
        int n = vals.size();
        vector<long long> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int v = vals[i-1];
            int j = lower_bound(vals.begin(), vals.end(), v - 2) - vals.begin(); // first idx with val >= v-2
            long long prevBest = (j == 0) ? 0 : dp[j];
            dp[i] = max(dp[i-1], dmg[i-1] + prevBest);
        }
        return dp[n];
    }
};
