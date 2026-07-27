// Link: https://leetcode.com/problems/zero-array-transformation-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q) SC: O(n)
// Approach: difference array counting how many queries cover each index.
// Each covering query can decrement that index by at most 1, so index i
// can reach 0 iff its coverage count >= nums[i].
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (auto& q : queries) {
            diff[q[0]]++;
            diff[q[1] + 1]--;
        }
        int cover = 0;
        for (int i = 0; i < n; i++) {
            cover += diff[i];
            if (cover < nums[i]) return false;
        }
        return true;
    }
};
