// Link: https://leetcode.com/problems/container-with-most-water/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: two pointers from both ends; always move the shorter side inward since it's the bottleneck
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, best = 0;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            best = max(best, area);
            if (height[l] < height[r]) l++;
            else r--;
        }
        return best;
    }
};
