// Link: https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * 1024 + k * 1024)  SC: O(1024)
// Approach: group indices by i%k. dp[x] = min changes over processed groups
// so that xor of chosen values equals x. For each group, default option is
// "change everything" (min(dp) + groupSize), then improve using each distinct
// value present in the group (keep unchanged elements of that value).
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
            unordered_map<int,int> cnt;
            for (int v : groups[g]) cnt[v]++;
            int size = groups[g].size();
            int base = *min_element(dp.begin(), dp.end());
            vector<int> ndp(MAXV, base == INT_MAX ? INT_MAX : base + size);
            for (int x = 0; x < MAXV; x++) {
                if (dp[x] == INT_MAX) continue;
                for (auto& [v, c] : cnt) {
                    int nx = x ^ v;
                    int cost = dp[x] + (size - c);
                    if (cost < ndp[nx]) ndp[nx] = cost;
                }
            }
            dp = ndp;
        }
        return dp[0];
    }
};
