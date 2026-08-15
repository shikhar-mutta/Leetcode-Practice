// Link: https://leetcode.com/problems/maximize-value-of-function-in-a-ball-passing-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size();
        const int LOG = 35;
        vector<vector<int>> up(LOG, vector<int>(n));
        vector<vector<long long>> sum(LOG, vector<long long>(n));
        for (int i = 0; i < n; i++) { up[0][i] = receiver[i]; sum[0][i] = receiver[i]; }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j-1][up[j-1][i]];
                sum[j][i] = sum[j-1][i] + sum[j-1][up[j-1][i]];
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long total = i, cur = i, rem = k;
            for (int j = 0; j < LOG; j++) {
                if (rem & (1LL << j)) {
                    total += sum[j][cur];
                    cur = up[j][cur];
                }
            }
            ans = max(ans, total);
        }
        return ans;
    }
};
