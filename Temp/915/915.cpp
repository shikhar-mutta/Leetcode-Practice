// Link: https://leetcode.com/problems/partition-array-into-disjoint-intervals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int leftMax = nums[0], curMax = nums[0], idx = 0;
        for (int i = 1; i < (int)nums.size(); i++) {
            curMax = max(curMax, nums[i]);
            if (nums[i] < leftMax) {
                leftMax = curMax;
                idx = i;
            }
        }
        return idx + 1;
    }
};
