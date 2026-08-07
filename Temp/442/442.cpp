// Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) extra
// Approach: negate the value at index |nums[i]|-1 to mark seen; a positive
// value found there next time means it's a duplicate
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int x : nums) {
            int idx = abs(x) - 1;
            if (nums[idx] < 0) res.push_back(idx + 1);
            else nums[idx] = -nums[idx];
        }
        return res;
    }
};
