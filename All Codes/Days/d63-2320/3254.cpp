// Link: https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
// Approach: len[i] = length of the run of consecutive increasing-by-1
// values ending at i. A k-size window ending at i is valid (max element)
// iff len[i] >= k, in which case the answer is nums[i] (the last, largest
// element); otherwise -1.
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> len(n, 1);

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1)
                len[i] = len[i - 1] + 1;
        }

        vector<int> ans;
        for (int i = k - 1; i < n; i++) {
            if (len[i] >= k)
                ans.push_back(nums[i]);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};
