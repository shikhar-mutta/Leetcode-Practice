// Link: https://leetcode.com/problems/path-existence-queries-in-a-graph-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> group(n);
        int g = 0;
        group[0] = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff) g++;
            group[i] = g;
        }
        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(group[q[0]] == group[q[1]]);
        }
        return ans;
    }
};
