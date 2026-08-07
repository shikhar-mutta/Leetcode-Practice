// Link: https://leetcode.com/problems/trapping-rain-water/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: two pointers from both ends tracking leftMax/rightMax; water at the shorter side's pointer = max - height
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = 0, water = 0;
        while (l < r) {
            if (height[l] <= height[r]) {
                leftMax = max(leftMax, height[l]);
                water += leftMax - height[l];
                l++;
            } else {
                rightMax = max(rightMax, height[r]);
                water += rightMax - height[r];
                r--;
            }
        }
        return water;
    }
};
