// Link: https://leetcode.com/problems/collecting-chocolates/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> minCostForType(nums.begin(), nums.end());
        long long best = LLONG_MAX;

        for (int k = 0; k < n; k++) {
            if (k > 0) {
                for (int i = 0; i < n; i++) {
                    int rotatedIdx = (i - k % n + n) % n;
                    minCostForType[i] = min(minCostForType[i], nums[rotatedIdx]);
                }
            }
            long long sum = (long long)k * x;
            for (int v : minCostForType) sum += v;
            best = min(best, sum);
        }
        return best;
    }
};
