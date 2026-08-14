// Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) { return nums[a] > nums[b]; });
        vector<int> chosen(idx.begin(), idx.begin() + k);
        sort(chosen.begin(), chosen.end());
        vector<int> res;
        for (int i : chosen) res.push_back(nums[i]);
        return res;
    }
};
