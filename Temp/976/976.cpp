// Link: https://leetcode.com/problems/largest-perimeter-triangle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 2; i--) {
            if (nums[i-2] + nums[i-1] > nums[i]) return nums[i-2] + nums[i-1] + nums[i];
        }
        return 0;
    }
};
