// Link: https://leetcode.com/problems/rotate-non-negative-elements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: negative elements stay fixed in place; collect the
// non-negative values in order, rotate that subsequence (new[i] =
// old[(i+k) % count]), then write the rotated values back into their
// original positions.
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> vals;
        vector<int> pos;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] >= 0) { vals.push_back(nums[i]); pos.push_back(i); }
        }
        int n = vals.size();
        if (n == 0) return nums;
        int s = k % n;

        vector<int> res = nums;
        for (int i = 0; i < n; i++) res[pos[i]] = vals[(i + s) % n];
        return res;
    }
};
