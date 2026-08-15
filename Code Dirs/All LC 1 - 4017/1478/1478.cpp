// Link: https://leetcode.com/problems/allocate-mailboxes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());
        int n = houses.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int l = i, r = j, sum = 0;
                while (l < r) {
                    sum += houses[r] - houses[l];
                    l++; r--;
                }
                cost[i][j] = sum;
            }
        }

        vector<vector<int>> dp(k + 1, vector<int>(n, INT_MAX / 2));
        for (int j = 0; j < n; j++) dp[1][j] = cost[0][j];

        for (int b = 2; b <= k; b++) {
            for (int j = b - 1; j < n; j++) {
                for (int i = b - 2; i < j; i++) {
                    dp[b][j] = min(dp[b][j], dp[b-1][i] + cost[i+1][j]);
                }
            }
        }
        return dp[k][n-1];
    }
};
