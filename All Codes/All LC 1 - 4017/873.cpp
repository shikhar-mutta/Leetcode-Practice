// Link: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> idx;
        for (int i = 0; i < n; i++) idx[arr[i]] = i;

        vector<vector<int>> dp(n, vector<int>(n, 2));
        int best = 0;
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int diff = arr[k] - arr[j];
                auto it = idx.find(diff);
                if (it != idx.end() && it->second < j) {
                    int i = it->second;
                    dp[j][k] = dp[i][j] + 1;
                    best = max(best, dp[j][k]);
                }
            }
        }
        return best >= 3 ? best : 0;
    }
};
