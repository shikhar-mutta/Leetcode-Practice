// Link: https://leetcode.com/problems/reach-end-of-array-with-max-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: A jump from i to j scores nums[i]*(j-i), so it's always optimal
// to jump one step at a time using the maximum value seen so far as the
// "from" multiplier. Track a running max (excluding the last index, since
// no jump starts there) and sum it at each step.
class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0;
        int mx = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            mx = max(mx, nums[i]);
            ans += mx;
        }

        return ans;
    }
};
