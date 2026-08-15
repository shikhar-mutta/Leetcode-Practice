// Link: https://leetcode.com/problems/minimum-absolute-difference-queries/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int maxVal = 100;
        vector<vector<int>> prefix(n + 1, vector<int>(maxVal + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int v = 1; v <= maxVal; v++) prefix[i+1][v] = prefix[i][v];
            prefix[i+1][nums[i]]++;
        }

        vector<int> res;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int prev = -1, best = INT_MAX;
            for (int v = 1; v <= maxVal; v++) {
                if (prefix[r+1][v] - prefix[l][v] > 0) {
                    if (prev != -1) best = min(best, v - prev);
                    prev = v;
                }
            }
            res.push_back(best == INT_MAX ? -1 : best);
        }
        return res;
    }
};
