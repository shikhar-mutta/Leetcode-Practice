// Link: https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int best = INT_MAX;
        for (int i = 0; i + k - 1 < (int)nums.size(); i++) {
            best = min(best, nums[i + k - 1] - nums[i]);
        }
        return best;
    }
};
