// Link: https://leetcode.com/problems/count-good-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: a subarray is good iff the OR of all its elements is itself
// present in the subarray, i.e. some element is a bitwise superset of every
// other element. Count, for each index i, subarrays where nums[i] is that
// dominant element: find l[i] = nearest left index NOT a bitwise subset of
// nums[i] (ties broken via strict <, so equal values attribute to one
// side), and r[i] = nearest right index not a subset, via two monotonic
// stacks. Sum (i-l[i])*(r[i]-i) over all i.
class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n, -1), r(n, n);
        vector<int> stk;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (!stk.empty() && nums[stk.back()] < x && (nums[stk.back()] | x) == x) {
                stk.pop_back();
            }
            l[i] = stk.empty() ? -1 : stk.back();
            stk.push_back(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && (nums[stk.back()] | nums[i]) == nums[i]) {
                stk.pop_back();
            }
            r[i] = stk.empty() ? n : stk.back();
            stk.push_back(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) ans += (long long)(i - l[i]) * (r[i] - i);
        return ans;
    }
};
