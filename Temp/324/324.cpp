// Link: https://leetcode.com/problems/wiggle-sort-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
// Approach: sort a copy, fill even indices with the smaller half (descending)
// and odd indices with the larger half (descending) to guarantee strict wiggle
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int mid = (n + 1) / 2;
        int lo = mid - 1, hi = n - 1;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) nums[i] = sorted[lo--];
            else nums[i] = sorted[hi--];
        }
    }
};
