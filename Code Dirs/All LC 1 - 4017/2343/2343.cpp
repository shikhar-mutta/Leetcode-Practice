// Link: https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> res;
        for (auto& q : queries) {
            int k = q[0], trim = q[1];
            vector<pair<string,int>> keyed(n);
            for (int i = 0; i < n; i++) {
                keyed[i] = {nums[i].substr(nums[i].size() - trim), i};
            }
            sort(keyed.begin(), keyed.end());
            res.push_back(keyed[k - 1].second);
        }
        return res;
    }
};
