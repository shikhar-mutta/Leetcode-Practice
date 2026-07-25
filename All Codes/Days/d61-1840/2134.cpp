// Link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: let k be the total count of 1's - that's the fixed size of the
// final grouped block. Since the array is circular, slide a window of
// length k around it and count how many 0's fall inside; each 0 in the
// window needs one swap with a 1 outside it to fill the window with all
// 1's, so the answer is the minimum zero-count over all k circular
// windows, found via a sliding window that adds/removes one element per
// shift.
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = accumulate(nums.begin(), nums.end(), 0);
        if (k == 0 || k == n)
            return 0;

        // count zeros in the first window [0, k)
        int zeros = 0;
        for (int i = 0; i < k; ++i)
            if (nums[i] == 0)
                ++zeros;

        int minZeros = zeros;
        for (int i = 1; i < n; ++i) {
            // window [i, i+k) circularly: remove nums[i-1], add nums[i+k-1]
            if (nums[i - 1] == 0)
                --zeros;
            if (nums[(i + k - 1) % n] == 0)
                ++zeros;
            minZeros = min(minZeros, zeros);
        }
        return minZeros;
    }
};
