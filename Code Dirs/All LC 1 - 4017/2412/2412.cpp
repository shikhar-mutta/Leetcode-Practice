// Link: https://leetcode.com/problems/minimum-money-required-before-transactions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long totalLoss = 0;
        for (auto &t : transactions) totalLoss += max(0, t[0] - t[1]);

        long long ans = 0;
        for (auto &t : transactions) {
            long long loss = max(0, t[0] - t[1]);
            long long need = totalLoss - loss + t[0];
            ans = max(ans, need);
        }
        return ans;
    }
};
