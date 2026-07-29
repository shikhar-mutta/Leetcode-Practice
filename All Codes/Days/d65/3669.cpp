// Link: https://leetcode.com/problems/balanced-k-factor-decomposition/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestDiff = INT_MAX;
    vector<int> bestCombo;

    void dfs(int remaining, int k, int startDiv, vector<int>& cur) {
        if (k == 1) {
            cur.push_back(remaining);
            int mn = *min_element(cur.begin(), cur.end());
            int mx = *max_element(cur.begin(), cur.end());
            if (mx - mn < bestDiff) {
                bestDiff = mx - mn;
                bestCombo = cur;
            }
            cur.pop_back();
            return;
        }
        for (int d = startDiv; (long long)d * d <= remaining; d++) {
            if (remaining % d != 0) continue;
            cur.push_back(d);
            dfs(remaining / d, k - 1, d, cur);
            cur.pop_back();
        }
    }

    vector<int> minDifference(int n, int k) {
        vector<int> cur;
        dfs(n, k, 1, cur);
        return bestCombo;
    }
};
