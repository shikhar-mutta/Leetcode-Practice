// Link: https://leetcode.com/problems/kth-smallest-subarray-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countLessEqual(vector<int>& nums, long long target) {
        int left = 0;
        long long sum = 0, count = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            sum += nums[right];
            while (sum > target) {
                sum -= nums[left];
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }

    int kthSmallestSubarraySum(vector<int>& nums, int k) {
        long long lo = *min_element(nums.begin(), nums.end());
        long long hi = 0;
        for (int x : nums) hi += x;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countLessEqual(nums, mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return (int)lo;
    }
};
