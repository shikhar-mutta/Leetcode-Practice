// Link: https://leetcode.com/problems/number-of-zero-filled-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: scan and track the length of the current run of consecutive
// zeros. Whenever that run ends (hit a nonzero after zeros, or reach the
// end of the array while still in a zero run), a run of length z
// contributes z*(z+1)/2 zero-filled subarrays (all its contiguous
// sub-runs), add that to the running answer and reset the run length.
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        long long int ans = 0;
        long long int zeros = 0;
        int n = nums.size();

        if (nums[0] == 0) {
            zeros++;
        }

        for (int i = 1; i < n; i++) {

            if (nums[i] == 0) {
                zeros++;

                if (i == n - 1) {

                    ans = zeros * (zeros + 1) / 2 + ans;
                    zeros = 0;
                }
            }

            if ((nums[i] != 0) && (nums[i - 1]) == 0) {

                ans = zeros * (zeros + 1) / 2 + ans;
                zeros = 0;
            }
        }

        if (n == 1) {
            return zeros;
        }

        return ans;
    }
};
