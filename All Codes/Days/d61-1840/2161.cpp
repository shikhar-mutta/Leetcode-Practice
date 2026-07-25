// Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n)
// Approach: fill the less-than-pivot elements into ans from the left in a
// forward pass (preserves their relative order), and the greater-than-pivot
// elements into ans from the right in a backward pass (filling from the
// last slot inward as the scan moves right-to-left also preserves their
// original relative order). Whatever gap remains in the middle (l..r) is
// exactly the count of elements equal to pivot, filled with pivot itself.
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        int n = nums.size();
        int l = 0;
        int r = n - 1;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot)
                ans[l++] = nums[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > pivot)
                ans[r--] = nums[i];
        }
        while (l <= r) {
            ans[l++] = pivot;
        }
        return ans;
    }
};
