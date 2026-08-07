// Link: https://leetcode.com/problems/find-peak-element/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n)  SC: O(1)
// Approach: binary search toward the ascending side; a peak always exists in that direction
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < nums[mid+1]) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
