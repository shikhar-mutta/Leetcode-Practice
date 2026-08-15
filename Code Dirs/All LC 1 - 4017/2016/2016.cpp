// Link: https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minSoFar = nums[0];
        int ans = -1;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] > minSoFar) ans = max(ans, nums[i] - minSoFar);
            minSoFar = min(minSoFar, nums[i]);
        }
        return ans;
    }
};
