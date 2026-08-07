// Link: https://leetcode.com/problems/24-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) bounded (4 numbers) SC: O(1)
// Approach: recursive backtracking — repeatedly pick two numbers, combine with +,-,*,/ (both subtraction orders and division where valid), replace them with the result, recurse until one number remains and check if it's ~24.
class Solution {
    bool solve(vector<double>& nums) {
        int n = nums.size();
        if (n == 1) return abs(nums[0] - 24.0) < 1e-6;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                vector<double> next;
                for (int k = 0; k < n; k++) if (k != i && k != j) next.push_back(nums[k]);
                vector<double> candidates = {nums[i]+nums[j], nums[i]-nums[j], nums[i]*nums[j]};
                if (abs(nums[j]) > 1e-9) candidates.push_back(nums[i]/nums[j]);
                for (double val : candidates) {
                    next.push_back(val);
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }
};
