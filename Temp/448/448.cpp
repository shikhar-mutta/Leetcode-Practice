// Link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) extra
// Approach: negate value at index |nums[i]|-1 to mark presence; indices
// still positive at the end correspond to missing numbers
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int x : nums) {
            int idx = abs(x) - 1;
            if (nums[idx] > 0) nums[idx] = -nums[idx];
        }
        vector<int> res;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] > 0) res.push_back(i + 1);
        }
        return res;
    }
};
