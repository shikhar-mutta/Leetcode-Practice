// Link: https://leetcode.com/problems/reach-end-of-array-with-max-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        int curMax = nums[0];
        for (int i = 0; i < n - 1; i++) {
            curMax = max(curMax, nums[i]);
            total += curMax;
        }
        return total;
    }
};
