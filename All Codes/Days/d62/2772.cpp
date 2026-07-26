// Link: https://leetcode.com/problems/apply-operations-to-make-all-array-elements-equal-to-zero/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n) for the difference array
// Approach: greedy left to right with a difference array tracking active
// length-k subtract-1 operations. At each index, `running` gives the total
// already subtracted here; whatever remains of nums[i] must be knocked out by
// a NEW length-k window starting exactly at i (starting later would leave
// nums[i] nonzero forever, since only windows starting at or before i affect
// it). If remaining is negative (over-subtracted) or there's no room left for
// a full window, it's infeasible.
class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> diff(
            n + 1, 0);         // difference array for tracking cumulative ops
        long long running = 0; // cumulative operations affecting current index

        for (int i = 0; i < n; ++i) {
            running += diff[i];
            long long remaining = nums[i] - running;

            if (remaining < 0)
                return false; // over-subtracted: impossible
            if (remaining > 0) {
                if (i + k > n)
                    return false;         // can't fit a length-k window
                running += remaining;     // apply 'remaining' ops starting here
                diff[i + k] -= remaining; // those ops end at i+k
            }
        }
        return true;
    }
};
