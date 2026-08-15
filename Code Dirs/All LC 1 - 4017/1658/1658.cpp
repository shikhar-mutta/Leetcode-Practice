// Link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total = 0;
        for (int v : nums) total += v;
        long long target = total - x;
        if (target < 0) return -1;
        int n = nums.size();
        int left = 0;
        long long sum = 0;
        int best = -1;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum > target && left <= right) {
                sum -= nums[left];
                left++;
            }
            if (sum == target) best = max(best, right - left + 1);
        }
        if (best == -1) return -1;
        return n - best;
    }
};
