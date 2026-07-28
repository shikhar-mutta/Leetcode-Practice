// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: dedup and sort. For each starting value nums[i], the window of
// values fitting in [nums[i], nums[i]+n-1] can all stay unchanged (found via
// binary search); operations needed = n - window size.
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int m = nums.size();
        int best = 0;
        for (int i = 0; i < m; i++) {
            int limit = nums[i] + n - 1;
            int j = upper_bound(nums.begin(), nums.end(), limit) - nums.begin();
            best = max(best, j - i);
        }
        return n - best;
    }
};
