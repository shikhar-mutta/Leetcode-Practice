// Link: https://leetcode.com/problems/two-sum-less-than-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums.size() - 1;
        int best = -1;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            if (sum < k) {
                best = max(best, sum);
                lo++;
            } else {
                hi--;
            }
        }
        return best;
    }
};
