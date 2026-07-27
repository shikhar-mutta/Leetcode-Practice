// Link: https://leetcode.com/problems/number-of-centered-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n)
// Approach: for each start index, extend the subarray right while
// tracking the running sum and a set of contained values; count it if
// the sum equals some element already seen in the subarray.
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            unordered_set<int> seen;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                seen.insert(nums[j]);
                if (seen.count((int)sum)) ans++;
            }
        }
        return ans;
    }
};
