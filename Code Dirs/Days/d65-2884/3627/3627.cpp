// Link: https://leetcode.com/problems/maximum-median-sum-of-subsequences-of-size-3/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int groups = n / 3;
        long long sum = 0;
        int idx = groups;
        for (int cnt = 0; cnt < groups; cnt++) {
            sum += nums[idx];
            idx += 2;
        }
        return sum;
    }
};
