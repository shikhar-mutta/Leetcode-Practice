// Link: https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 30), SC: O(1) extra (nums mutated in place)
// Approach: For each i, extend backward accumulating OR into nums[j] (since
// bits only ever get set, at most ~30 distinct OR values exist per position
// before nums[j] absorbs nums[i] entirely, so the inner loop breaks early
// once nums[j] already contains nums[i]'s bits). Track the minimum window
// length whenever an accumulated OR reaches k.
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            if(nums[i]>=k) return 1;
            for (int j = i-1; j>=0; j--) {
                if((nums[j] | nums[i]) == nums[j])
                    break;
                nums[j] |= nums[i];
                if(nums[j] >= k){
                    ans = min(ans, i-j+1);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
