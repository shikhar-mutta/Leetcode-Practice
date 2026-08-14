// Link: https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> runLen(n);
        runLen[0] = 1;
        for (int i = 1; i < n; i++) {
            runLen[i] = (nums[i] == nums[i-1] + 1) ? runLen[i-1] + 1 : 1;
        }
        vector<int> res;
        for (int i = 0; i + k <= n; i++) {
            int end = i + k - 1;
            res.push_back(runLen[end] >= k ? nums[end] : -1);
        }
        return res;
    }
};
