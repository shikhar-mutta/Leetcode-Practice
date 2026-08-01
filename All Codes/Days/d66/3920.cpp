// Link: https://leetcode.com/problems/maximize-fixed-points-after-deletions/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: a kept element at original index i, value x, can only ever
// land at a post-deletion position p<=i (deletions only shift left), so it
// can only be a fixed point if x<=i. For several kept elements to ALL be
// fixed simultaneously, their assigned positions must be their rank order
// among themselves, which works out to requiring the x-values to be
// strictly increasing when candidates are sorted by key=(i-x, x). That
// reduces the problem to the length of the longest strictly increasing
// subsequence of x over that sorted order, computed via patience sorting.
class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        vector<pair<int,int>> cand; // (i-x, x)
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i - nums[i] >= 0) cand.push_back({i - nums[i], nums[i]});
        }
        sort(cand.begin(), cand.end());
        vector<int> lis;
        for (auto& [k, x] : cand) {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if (it == lis.end()) lis.push_back(x);
            else *it = x;
        }
        return lis.size();
    }
};
