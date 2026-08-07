// Link: https://leetcode.com/problems/house-robber-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: circular constraint splits into two linear house-robber runs — excluding the last house,
// or excluding the first — take the max of both
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robLinear(nums, 0, n-2), robLinear(nums, 1, n-1));
    }
private:
    int robLinear(vector<int>& nums, int lo, int hi) {
        int prev2 = 0, prev1 = 0;
        for (int i = lo; i <= hi; i++) {
            int cur = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
