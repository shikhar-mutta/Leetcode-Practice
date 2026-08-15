// Link: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        long long maxSum = 0, minSum = 0, cur = 0;
        for (int x : nums) {
            cur += x;
            maxSum = max(maxSum, cur);
            minSum = min(minSum, cur);
        }
        return (int)(maxSum - minSum);
    }
};
