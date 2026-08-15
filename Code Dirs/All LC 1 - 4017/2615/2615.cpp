// Link: https://leetcode.com/problems/sum-of-distances/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) groups[nums[i]].push_back(i);

        vector<long long> ans(n, 0);
        for (auto &[val, idxs] : groups) {
            int m = idxs.size();
            vector<long long> prefix(m + 1, 0);
            for (int i = 0; i < m; i++) prefix[i+1] = prefix[i] + idxs[i];

            for (int i = 0; i < m; i++) {
                long long leftSum = (long long)idxs[i] * i - prefix[i];
                long long rightSum = (prefix[m] - prefix[i+1]) - (long long)idxs[i] * (m - i - 1);
                ans[idxs[i]] = leftSum + rightSum;
            }
        }
        return ans;
    }
};
