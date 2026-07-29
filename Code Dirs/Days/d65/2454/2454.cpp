// Link: https://leetcode.com/problems/next-greater-element-iv/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: two monotonic stacks of indices. s1 holds candidates awaiting their first greater;
// s2 holds candidates (already found first-greater) awaiting their second greater. For each i,
// pop s2 for anyone whose second-greater is nums[i]; then move indices popped from s1 (whose
// first-greater is nums[i]) into s2, preserving order; push i onto s1.
class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s1, s2;

        for (int i = 0; i < n; i++) {
            while (!s2.empty() && nums[s2.top()] < nums[i]) {
                ans[s2.top()] = nums[i];
                s2.pop();
            }
            vector<int> temp;
            while (!s1.empty() && nums[s1.top()] < nums[i]) {
                temp.push_back(s1.top());
                s1.pop();
            }
            for (int j = (int)temp.size() - 1; j >= 0; j--) s2.push(temp[j]);
            s1.push(i);
        }
        return ans;
    }
};
