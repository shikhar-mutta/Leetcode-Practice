// Link: https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m), SC: O(n)
// Approach: Precompute the sorted list of indices where nums equals x, then
// each query's k-th occurrence is just a[k-1] if enough occurrences exist,
// else -1.
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m), a;

        for (int i = 0; i < n; i++) {
            if (x == nums[i])
                a.push_back(i);
        }

        for (int i = 0; i < m; i++) {
            if (a.size() >= queries[i]) {
                ans[i] = a[queries[i] - 1];
            } else {
                ans[i] = -1;
            }
        }
        return ans;
    }
};
