// Link: https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int best = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            best = max(best, abs(nums[i] - nums[j]));
        }
        return best;
    }
};
