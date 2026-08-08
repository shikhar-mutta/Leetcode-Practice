// Link: https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size() && k > 0 && nums[i] < 0; i++) {
            nums[i] = -nums[i];
            k--;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (k % 2 == 1) {
            int minVal = *min_element(nums.begin(), nums.end());
            sum -= 2 * minVal;
        }
        return sum;
    }
};
