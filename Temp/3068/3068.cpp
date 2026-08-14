// Link: https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long base = 0;
        vector<int> gains;
        for (int x : nums) {
            base += x;
            gains.push_back((x ^ k) - x);
        }
        sort(gains.rbegin(), gains.rend());
        long long total = base;
        int cnt = 0;
        int minPosGain = INT_MAX;
        int maxNegGain = INT_MIN;
        for (int g : gains) {
            if (g > 0) {
                total += g;
                cnt++;
                minPosGain = min(minPosGain, g);
            } else {
                maxNegGain = max(maxNegGain, g);
            }
        }
        if (cnt % 2 != 0) {
            // remove the smallest positive gain, or add the best negative gain, whichever loses less
            long long optA = total - minPosGain;
            long long optB = (maxNegGain == INT_MIN) ? LLONG_MIN : total + maxNegGain;
            total = max(optA, optB);
        }
        return total;
    }
};
