// Link: https://leetcode.com/problems/weighted-sum-of-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<int> depth(n);
        depth[0] = 1;
        int h = 1;
        for (int i = 1; i < n; i++) {
            depth[i] = depth[parent[i]] + 1;
            h = max(h, depth[i]);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (long long)nums[i] * (h - depth[i] + 1);
        }
        return ans;
    }
};
