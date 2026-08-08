// Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int drops = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) drops++;
        }
        return drops <= 1;
    }
};
