// Link: https://leetcode.com/problems/wiggle-sort/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(1)
// Approach: sort array, then swap every adjacent pair starting at index 1
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i + 1 < (int)nums.size(); i += 2) {
            swap(nums[i], nums[i + 1]);
        }
    }
};
