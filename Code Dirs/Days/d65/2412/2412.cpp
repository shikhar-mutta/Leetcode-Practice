// Link: https://leetcode.com/problems/minimum-money-required-before-transactions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(1)
// Approach: totalLoss = sum of max(0, cost-cashback) (worst-case ordering baseline). For each
// transaction done first, required = totalLoss - its own loss + its full cost; answer is the max.
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long totalLoss = 0;
        for (auto& t : transactions) totalLoss += max(0, t[0] - t[1]);

        long long ans = 0;
        for (auto& t : transactions) {
            long long loss = max(0, t[0] - t[1]);
            long long needed = totalLoss - loss + t[0];
            ans = max(ans, needed);
        }
        return ans;
    }
};
