// Link: https://leetcode.com/problems/minimum-replacements-to-sort-the-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(1)
// Approach: scan right to left, tracking max allowed value; if nums[i] exceeds it, split into
// k = ceil(nums[i]/maxAllowed) pieces (k-1 replacements), new maxAllowed = nums[i]/k (floor).
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int maxAllowed = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] <= maxAllowed) {
                maxAllowed = nums[i];
                continue;
            }
            long long k = (nums[i] + maxAllowed - 1) / maxAllowed;
            ans += k - 1;
            maxAllowed = nums[i] / k;
        }
        return ans;
    }
};
