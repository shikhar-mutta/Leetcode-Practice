// Link: https://leetcode.com/problems/3sum-closest/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(1)
// Approach: sort, fix leftmost value, two-pointer the rest tracking the sum closest to target
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int best = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < abs(best - target)) best = sum;
                if (sum < target) l++;
                else if (sum > target) r--;
                else return sum;
            }
        }
        return best;
    }
};
