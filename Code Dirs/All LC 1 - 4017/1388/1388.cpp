// Link: https://leetcode.com/problems/pizza-with-3n-slices/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pickNonAdjacent(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                int skip = dp[i-1][j];
                int take = (i >= 2 ? dp[i-2][j-1] : (j == 1 ? 0 : INT_MIN / 2)) + arr[i-1];
                dp[i][j] = max(skip, take);
            }
        }
        return dp[n][k];
    }

    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size() / 3;
        vector<int> a1(slices.begin(), slices.end() - 1);
        vector<int> a2(slices.begin() + 1, slices.end());
        return max(pickNonAdjacent(a1, n), pickNonAdjacent(a2, n));
    }
};
