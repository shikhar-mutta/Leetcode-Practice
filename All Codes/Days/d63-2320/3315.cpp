// Link: https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 32), SC: O(1)
// Approach: We need the smallest ans[i] with ans[i] | (ans[i]+1) == nums[i].
// If nums[i]==2 (prime, no valid answer since 2 has no lower zero bit to
// exploit), it's -1. Otherwise, find the lowest zero bit i>=1 in nums[i]'s
// binary form and clear the bit just below it (x ^ (1<<(i-1))) — this
// yields the minimal x satisfying the OR-with-successor condition.
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int x : nums) {
            if (x == 2) {
                ans.push_back(-1);
                continue;
            }

            for (int i = 1; i < 32; i++) {
                if (((x >> i) & 1) == 0) {
                    ans.push_back(x ^ (1 << (i - 1)));
                    break;
                }
            }
        }

        return ans;
    }
};
