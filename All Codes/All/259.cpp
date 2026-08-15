// Link: https://leetcode.com/problems/3sum-smaller/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(1) extra
// Approach: sort, fix leftmost value, two-pointer the rest; when nums[i]+nums[l]+nums[r] < target,
// every value between l and r paired with l also satisfies it (r-l count at once), advance l
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), count = 0;
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] < target) {
                    count += r - l;
                    l++;
                } else {
                    r--;
                }
            }
        }
        return count;
    }
};
