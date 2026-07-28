// Link: https://leetcode.com/problems/24-game/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(1)  (fixed 4 numbers, bounded branching)  SC: O(1)
// Approach: brute-force recursion. Pick any pair from the current list,
// combine with +,-,*,/ (both subtraction/division orders), replace the
// pair with the result, and recurse until one number remains, checking
// if it's ~24.
class Solution {
    bool solve(vector<double>& nums) {
        int n = nums.size();
        if (n == 1) return fabs(nums[0] - 24.0) < 1e-6;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                vector<double> next;
                for (int k = 0; k < n; k++) if (k != i && k != j) next.push_back(nums[k]);
                double a = nums[i], b = nums[j];
                vector<double> candidates = {a + b, a - b, a * b};
                if (fabs(b) > 1e-9) candidates.push_back(a / b);
                for (double c : candidates) {
                    next.push_back(c);
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
