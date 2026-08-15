// Link: https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int hi = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return (hi - lo) > n / 2;
    }
};
