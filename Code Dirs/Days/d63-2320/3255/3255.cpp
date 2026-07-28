// Link: https://leetcode.com/problems/find-the-power-of-k-size-subarrays-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
// Approach: Sliding-window version: maintain a running count of the
// current consecutive increasing-by-1 streak as the window advances one
// element at a time; a window ending at j is valid iff that streak is >= k,
// in which case the answer is nums[j].
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);
        int count = 1;
        for (int i = 1; i < k; i++) {
            if (nums[i] == nums[i - 1] + 1)
                count++;
            else
                count = 1;
        }
        if (count == k)
            ans[0] = nums[k - 1];
        int i = 1, j = k;
        while (j < n) {
            if (nums[j] == nums[j - 1] + 1)
                count++;
            else
                count = 1;
            if (count >= k)
                ans[i] = nums[j];
            i++;
            j++;
        }
        return ans;
    }
};
