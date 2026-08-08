// Link: https://leetcode.com/problems/knight-dialer/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int knightDialer(int n) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> moves = {
            {4,6}, {6,8}, {7,9}, {4,8}, {0,3,9},
            {}, {0,1,7}, {2,6}, {1,3}, {2,4}
        };
        vector<long long> dp(10, 1);
        for (int step = 1; step < n; step++) {
            vector<long long> next(10, 0);
            for (int d = 0; d < 10; d++)
                for (int nd : moves[d])
                    next[nd] = (next[nd] + dp[d]) % MOD;
            dp = next;
        }
        long long res = 0;
        for (int d = 0; d < 10; d++) res = (res + dp[d]) % MOD;
        return (int)res;
    }
};
