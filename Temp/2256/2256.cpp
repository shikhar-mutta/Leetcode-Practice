// Link: https://leetcode.com/problems/minimum-average-difference/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long prefix = 0;
        long long best = LLONG_MAX;
        int bestIdx = 0;
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            long long avg1 = prefix / (i + 1);
            long long avg2 = (i == n - 1) ? 0 : (total - prefix) / (n - i - 1);
            long long diff = abs(avg1 - avg2);
            if (diff < best) { best = diff; bestIdx = i; }
        }
        return bestIdx;
    }
};
