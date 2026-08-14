// Link: https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];

        vector<long long> ans;
        for (int q : queries) {
            int idx = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
            long long leftSum = (long long)q * idx - prefix[idx];
            long long rightSum = (prefix[n] - prefix[idx]) - (long long)q * (n - idx);
            ans.push_back(leftSum + rightSum);
        }
        return ans;
    }
};
