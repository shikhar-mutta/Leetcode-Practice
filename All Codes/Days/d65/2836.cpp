// Link: https://leetcode.com/problems/maximize-value-of-function-in-a-ball-passing-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log K), SC: O(N log K)
// Approach: binary lifting on the functional graph. up[j][v] = node reached after 2^j passes
// from v; sum[j][v] = total of the 2^j visited nodes' values along that path. For each start,
// combine k in binary using the lifting tables to get the sum after exactly k passes, plus the
// starting node itself; take the max over all starts.
class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size();
        int LOG = 1;
        while ((1LL << LOG) <= k) LOG++;
        LOG++;

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
            for (int j = 0; j < LOG && rem > 0; j++) {
                if (rem & 1) {
                    total += sum[j][cur];
                    cur = up[j][cur];
                }
                rem >>= 1;
            }
            ans = max(ans, total);
        }
        return ans;
    }
};
