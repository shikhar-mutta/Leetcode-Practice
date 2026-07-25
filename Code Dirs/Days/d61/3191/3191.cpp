// Link: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: greedy left-to-right sweep. Whenever nums[i] is 0, the only
// operation that can ever fix it is flipping the window [i, i+1, i+2] (any
// later flip starting further right leaves index i untouched, and it's
// never beneficial to flip a window that starts before an already-fixed
// index), so flip it immediately. If the last two elements aren't both 1
// after the sweep, no window can reach them, so it's impossible.
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ops = 0;
        for (int i = 0; i + 2 < n; ++i) {
            if (nums[i] == 0) {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ++ops;
            }
        }
        // last two elements must already be 1
        if (nums[n - 2] == 0 || nums[n - 1] == 0)
            return -1;
        return ops;
    }
};
