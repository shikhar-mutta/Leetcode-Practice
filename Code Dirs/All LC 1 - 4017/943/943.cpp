// Link: https://leetcode.com/problems/find-the-shortest-superstring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> overlap(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int maxLen = min(words[i].size(), words[j].size());
                for (int k = maxLen; k > 0; k--) {
                    if (words[i].substr(words[i].size() - k) == words[j].substr(0, k)) {
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }

        int full = 1 << n;
        vector<vector<int>> dp(full, vector<int>(n, 0));
        vector<vector<int>> parent(full, vector<int>(n, -1));
        for (int i = 0; i < n; i++) dp[1 << i][i] = words[i].size();

        for (int mask = 1; mask < full; mask++) {
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) continue;
                if (dp[mask][i] == 0 && mask != (1 << i)) continue;
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j)) continue;
                    int nmask = mask | (1 << j);
                    int cand = dp[mask][i] + (int)words[j].size() - overlap[i][j];
                    if (dp[nmask][j] == 0 || cand < dp[nmask][j]) {
                        dp[nmask][j] = cand;
                        parent[nmask][j] = i;
                    }
                }
            }
        }

        int bestLen = INT_MAX, bestEnd = -1;
        for (int i = 0; i < n; i++) {
            if (dp[full-1][i] < bestLen) {
                bestLen = dp[full-1][i];
                bestEnd = i;
            }
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

        string res = words[order[0]];
        for (int i = 1; i < (int)order.size(); i++) {
            int prev = order[i-1], curIdx = order[i];
            res += words[curIdx].substr(overlap[prev][curIdx]);
        }
        return res;
    }
};
