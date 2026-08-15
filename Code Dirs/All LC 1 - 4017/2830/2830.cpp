// Link: https://leetcode.com/problems/maximize-the-profit-as-the-salesman/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<vector<pair<int,int>>> byEnd(n);
        for (auto& o : offers) byEnd[o[1]].push_back({o[0], o[2]});
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i];
            for (auto& [start, gold] : byEnd[i])
                dp[i + 1] = max(dp[i + 1], dp[start] + gold);
        }
        return dp[n];
    }
};
