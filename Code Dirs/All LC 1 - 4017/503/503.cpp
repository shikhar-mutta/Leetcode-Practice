// Link: https://leetcode.com/problems/next-greater-element-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: monotonic decreasing stack of indices, iterate 2n times
// (mod n) to simulate the circular array
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> stk;
        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;
            while (!stk.empty() && nums[stk.top()] < nums[idx]) {
                res[stk.top()] = nums[idx];
                stk.pop();
            }
            if (i < n) stk.push(idx);
        }
        return res;
    }
};
