// Link: https://leetcode.com/problems/minimum-moves-to-pick-k-ones/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        int n = nums.size();
        vector<long long> pos;
        for (int i = 0; i < n; i++) if (nums[i] == 1) pos.push_back(i);
        int total = pos.size();

        vector<long long> prefix(total + 1, 0);
        for (int i = 0; i < total; i++) prefix[i+1] = prefix[i] + pos[i];

        auto cost = [&](int l, int r) -> long long {
            int mid = (l + r) / 2;
            long long leftCost = pos[mid] * (mid - l) - (prefix[mid] - prefix[l]);
            long long rightCost = (prefix[r+1] - prefix[mid+1]) - pos[mid] * (r - mid);
            return leftCost + rightCost;
        };

        long long best = LLONG_MAX;
        int yLo = max(0, k - maxChanges);
        int yHi = min(k, total);
        for (int y = yLo; y <= yHi; y++) {
            long long moveCost;
            if (y == 0) {
                moveCost = 0;
            } else {
                moveCost = LLONG_MAX;
                for (int l = 0; l + y - 1 < total; l++) {
                    int r = l + y - 1;
                    moveCost = min(moveCost, cost(l, r));
                }
            }
            long long total_ = moveCost + 2LL * (k - y);
            best = min(best, total_);
        }
        return best;
    }
};
