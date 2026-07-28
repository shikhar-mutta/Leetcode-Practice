// Link: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: for three indices i<j<k, sum of pairwise distances
// (j-i)+(k-j)+(k-i) simplifies to 2*(k-i), independent of the middle
// index. So for each value, only the first and last of a consecutive
// triple of its occurrences matter; scan each value's occurrence list
// with a window of 3 and take the minimum span, then double it.
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < (int)nums.size(); i++) pos[nums[i]].push_back(i);

        int best = INT_MAX;
        for (auto& [v, idx] : pos) {
            for (int m = 0; m + 2 < (int)idx.size(); m++) {
                best = min(best, idx[m+2] - idx[m]);
            }
        }
        return best == INT_MAX ? -1 : 2 * best;
    }
};
