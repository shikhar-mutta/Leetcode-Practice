// Link: https://leetcode.com/problems/house-robber-iv/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log(max-min))
// SC: O(1)
// Approach: binary search the minimum capability cap such that a greedy
// scan (rob any house with value <= cap, then skip the next adjacent
// house) can collect at least k non-adjacent houses. Feasibility is
// monotonic in cap, so binary search over [min(nums), max(nums)] finds
// the smallest capability that works.
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canRob(nums, mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
private:
    int canRob(vector<int>& nums, int cap) {
        int count = 0, i = 0, n = nums.size();
        while (i < n) {
            if (nums[i] <= cap) {
                ++count;
                i += 2;   // skip the adjacent house
            } else {
                ++i;
            }
        }
        return count;
    }
};
