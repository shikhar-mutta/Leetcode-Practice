// Link: https://leetcode.com/problems/find-the-shortest-superstring/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2 * 2^n)  SC: O(n * 2^n)
// Approach: precompute overlap[i][j] = longest suffix of words[i] that
// is a prefix of words[j]. Bitmask DP: dp[mask][i] = max total overlap
// achievable by an ordering of the words in mask ending with word i.
// Transition by appending an unused word j: dp[mask|1<<j][j] =
// max(dp[mask][i] + overlap[i][j]). Reconstruct the best-ending word
// order via parent pointers, then concatenate with overlaps trimmed.
class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> overlap(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int maxLen = min(words[i].size(), words[j].size());
                for (int len = maxLen; len > 0; len--) {
                    if (words[i].substr(words[i].size() - len) == words[j].substr(0, len)) {
                        overlap[i][j] = len;
                        break;
                    }
                }
            }
        }

        int full = 1 << n;
        vector<vector<int>> dp(full, vector<int>(n, -1));
        vector<vector<int>> parent(full, vector<int>(n, -1));
        for (int i = 0; i < n; i++) dp[1 << i][i] = 0;

        for (int mask = 1; mask < full; mask++) {
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i)) || dp[mask][i] < 0) continue;
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j)) continue;
                    int nmask = mask | (1 << j);
                    int val = dp[mask][i] + overlap[i][j];
                    if (val > dp[nmask][j]) {
                        dp[nmask][j] = val;
                        parent[nmask][j] = i;
                    }
                }
            }
        }

        int bestEnd = 0, bestVal = -1;
        for (int i = 0; i < n; i++) {
            if (dp[full - 1][i] > bestVal) { bestVal = dp[full - 1][i]; bestEnd = i; }
        }

        vector<int> order;
        int mask = full - 1, cur = bestEnd;
        while (cur != -1) {
            order.push_back(cur);
            int p = parent[mask][cur];
            mask ^= (1 << cur);
            cur = p;
        }
        reverse(order.begin(), order.end());

        string result = words[order[0]];
        for (int k = 1; k < n; k++) {
            int prev = order[k - 1], cur2 = order[k];
            result += words[cur2].substr(overlap[prev][cur2]);
        }
        return result;
    }
};
