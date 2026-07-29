// Link: https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N), SC: O(N)
// Approach: for a candidate target value v, frequency achievable = (elements already equal to
// v, free) + min(numOperations, elements in [v-k, v+k] that aren't already v, each shiftable to
// v with one operation). Since the count within any fixed-width window only changes at actual
// array values, it suffices to try every distinct value in nums as the target, using binary
// search on the sorted array for window bounds.
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = 0;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && nums[j] == nums[i]) j++;
            int exact = j - i;
            int v = nums[i];

            int lo = lower_bound(nums.begin(), nums.end(), v - k) - nums.begin();
            int hi = upper_bound(nums.begin(), nums.end(), v + k) - nums.begin();
            int windowCount = hi - lo;
            int changeable = windowCount - exact;

            ans = max(ans, exact + min(numOperations, changeable));
            i = j;
        }
        return ans;
    }
};
