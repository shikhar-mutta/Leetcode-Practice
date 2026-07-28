// Link: https://leetcode.com/problems/minimum-cost-to-move-between-indices/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q) SC: O(n)
// Approach: since nums is sorted, moving forward (l<r) only ever
// benefits from taking each step i-1->i at cost min(1, actualGap) —
// except the cost-1 "closest" edge only exists in a given direction if
// that gap is indeed the smaller of its two neighboring gaps, so build
// two prefix-sum arrays: s1 for the cost of the forward step i-1->i
// (uses the closest-edge cost 1 only if the LEFT gap of i-1 wasn't
// smaller, matching closest(i-1)==i), and s2 for the backward step
// i->i-1 (uses cost 1 only if the RIGHT gap of i isn't smaller,
// matching closest(i)==i-1). A query then reduces to a prefix-sum
// difference on whichever array matches the direction of travel.
class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> s1(n, 0), s2(n, 0);
        for (int i = 1; i < n; i++) {
            long long c1 = (i > 1 && nums[i-1] - nums[i-2] <= nums[i] - nums[i-1]) ? nums[i] - nums[i-1] : 1;
            long long c2 = (i < n - 1 && nums[i] - nums[i-1] > nums[i+1] - nums[i]) ? nums[i] - nums[i-1] : 1;
            s1[i] = s1[i-1] + c1;
            s2[i] = s2[i-1] + c2;
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < (int)queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1];
            ans[i] = (int)((l < r) ? s1[r] - s1[l] : s2[l] - s2[r]);
        }
        return ans;
    }
};
