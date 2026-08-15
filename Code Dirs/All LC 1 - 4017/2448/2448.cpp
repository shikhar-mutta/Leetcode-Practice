// Link: https://leetcode.com/problems/minimum-cost-to-make-array-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& nums, vector<int>& cost, long long target) {
        long long total = 0;
        for (int i = 0; i < (int)nums.size(); i++)
            total += (long long)abs(nums[i] - target) * cost[i];
        return total;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return nums[a] < nums[b]; });

        long long totalCostSum = accumulate(cost.begin(), cost.end(), 0LL);
        long long half = (totalCostSum + 1) / 2;
        long long acc = 0;
        int medianVal = nums[idx[0]];
        for (int i : idx) {
            acc += cost[i];
            if (acc >= half) { medianVal = nums[i]; break; }
        }
        return totalCost(nums, cost, medianVal);
    }
};
