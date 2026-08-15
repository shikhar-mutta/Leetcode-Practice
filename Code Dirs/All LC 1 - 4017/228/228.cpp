// Link: https://leetcode.com/problems/summary-ranges/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) extra (excluding output)
// Approach: scan for consecutive runs, format each as "a" (single) or "a->b" (range)
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int start = i;
            while (i + 1 < n && nums[i+1] == nums[i] + 1) i++;
            if (start == i) res.push_back(to_string(nums[start]));
            else res.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
        }
        return res;
    }
};
