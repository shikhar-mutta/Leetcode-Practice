// Link: https://leetcode.com/problems/minimize-or-of-remaining-elements-using-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums, int x, int k) {
        vector<pair<int,int>> closedGroups; // (runningAnd, size)
        int curRunning = -1, curSize = 0;
        for (int v : nums) {
            if (curRunning == -1) { curRunning = v; curSize = 1; }
            else { curRunning &= v; curSize++; }
            if ((curRunning & x) == 0) {
                closedGroups.push_back({curRunning, curSize});
                curRunning = -1; curSize = 0;
            }
        }
        // absorb any trailing unclosed segment backward into prior groups
        while (curRunning != -1 && !closedGroups.empty()) {
            auto [pr, ps] = closedGroups.back();
            closedGroups.pop_back();
            curRunning &= pr;
            curSize += ps;
            if ((curRunning & x) == 0) {
                closedGroups.push_back({curRunning, curSize});
                curRunning = -1; curSize = 0;
            }
        }
        if (curRunning != -1) return false;

        int merges = 0;
        for (auto& [r, s] : closedGroups) merges += s - 1;
        return merges <= k;
    }

    int minOrAfterOperations(vector<int>& nums, int k) {
        int ans = 0; // bits confirmed zeroable
        int minOr = 0;
        for (int b = 29; b >= 0; b--) {
            int test = ans | (1 << b);
            if (check(nums, test, k)) {
                ans = test;
            } else {
                minOr |= (1 << b);
            }
        }
        return minOr;
    }
};
