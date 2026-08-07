// Link: https://leetcode.com/problems/reverse-pairs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
// Approach: merge sort; while merging, count pairs where left[i] > 2*right[j]
// before doing the standard merge
class Solution {
    int mergeCount(vector<long long>& nums, int l, int r) {
        if (l >= r) return 0;
        int mid = (l + r) / 2;
        int count = mergeCount(nums, l, mid) + mergeCount(nums, mid + 1, r);

        int j = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (j <= r && nums[i] > 2 * nums[j]) j++;
            count += j - (mid + 1);
        }

        inplace_merge(nums.begin() + l, nums.begin() + mid + 1, nums.begin() + r + 1);
        return count;
    }

public:
    int reversePairs(vector<int>& nums) {
        vector<long long> v(nums.begin(), nums.end());
        return mergeCount(v, 0, v.size() - 1);
    }
};
