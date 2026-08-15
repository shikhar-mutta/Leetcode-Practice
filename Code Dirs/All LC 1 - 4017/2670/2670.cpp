// Link: https://leetcode.com/problems/find-the-distinct-difference-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            unordered_set<int> pre(nums.begin(), nums.begin() + i + 1);
            unordered_set<int> suf(nums.begin() + i + 1, nums.end());
            ans[i] = (int)pre.size() - (int)suf.size();
        }
        return ans;
    }
};
