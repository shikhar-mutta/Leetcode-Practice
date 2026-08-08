// Link: https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for (int i = 0; i + 1 < n; i++) total += abs(nums[i+1] - nums[i]);

        long long best = total;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long cur = total;
                if (i > 0) cur -= abs(nums[i] - nums[i-1]);
                if (j < n - 1) cur -= abs(nums[j+1] - nums[j]);
                if (i > 0) cur += abs(nums[j] - nums[i-1]);
                if (j < n - 1) cur += abs(nums[i] - nums[j+1]);
                best = max(best, cur);
            }
        }
        return (int)best;
    }
};
