// Link: https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        const int MAXV = 1024;
        vector<vector<int>> groups(k);
        for (int i = 0; i < n; i++) groups[i % k].push_back(nums[i]);

        vector<int> dp(MAXV, INT_MAX);
        dp[0] = 0;

        for (int g = 0; g < k; g++) {
            int m = groups[g].size();
            unordered_map<int, int> cnt;
            for (int v : groups[g]) cnt[v]++;

            int minPrev = *min_element(dp.begin(), dp.end());
            vector<int> ndp(MAXV, minPrev + m);

            for (int x = 0; x < MAXV; x++) {
                if (dp[x] == INT_MAX) continue;
                for (auto& [v, c] : cnt) {
                    int nx = x ^ v;
                    int cost = dp[x] + (m - c);
                    if (cost < ndp[nx]) ndp[nx] = cost;
                }
            }
            dp = ndp;
        }
        return dp[0];
    }
};
