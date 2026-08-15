// Link: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: single pass tracking, as k advances, the best (nums[i]-nums[j])
// seen for any valid i<j<k pair (maxDiff) and the running max value seen so
// far (maxI, a candidate future i). At each k, the best triplet value ending
// here is maxDiff*nums[k]; then update maxDiff using maxI (as a candidate i)
// against nums[k] (as a candidate j) before finally updating maxI itself.
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0, maxI = 0, maxDiff = 0;
        for (int k = 0; k < nums.size(); k++) {
            ans = max(ans, maxDiff * nums[k]);
            maxDiff = max(maxDiff, maxI - nums[k]);
            maxI = max(maxI, (long long)nums[k]);
        }
        return ans;
    }
};
