// Link: https://leetcode.com/problems/maximum-valid-pair-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MIN;
        int maxLeft = INT_MIN;
        for (int j = k; j < n; j++) {
            maxLeft = max(maxLeft, nums[j - k]);
            ans = max(ans, maxLeft + nums[j]);
        }
        return ans;
    }
};
