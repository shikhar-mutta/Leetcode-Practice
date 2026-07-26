// Link: https://leetcode.com/problems/find-all-good-indices/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n)
// Approach: precompute left[i] = length of the non-increasing run ending
// at i, right[i] = length of the non-decreasing run starting at i. Index
// i is good if the k elements before it are non-increasing (left[i-1] >=
// k) and the k elements after it are non-decreasing (right[i+1] >= k).
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] >= nums[i]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i + 1] >= nums[i]) {
                right[i] = right[i + 1] + 1;
            }
        }

        vector<int> ans;

        for (int i = k; i < n - k; i++) {
            if (left[i - 1] >= k && right[i + 1] >= k)
                ans.push_back(i);
        }

        return ans;
    }
};
