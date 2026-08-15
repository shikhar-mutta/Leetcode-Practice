// Link: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for (int x : nums) total += x;
        vector<int> res(n);
        long long leftSum = 0;
        for (int i = 0; i < n; i++) {
            long long rightSum = total - leftSum - nums[i];
            long long rightCount = n - i - 1;
            long long fromLeft = (long long)nums[i] * i - leftSum;
            long long fromRight = rightSum - (long long)nums[i] * rightCount;
            res[i] = (int)(fromLeft + fromRight);
            leftSum += nums[i];
        }
        return res;
    }
};
