// Link: https://leetcode.com/problems/maximum-average-subarray-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: sliding window of size k tracking sum; slide, keep max sum, divide by k at the end.
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        long long best = sum;
        for (int i = k; i < (int)nums.size(); i++) {
            sum += nums[i] - nums[i-k];
            best = max(best, sum);
        }
        return (double)best / k;
    }
};
