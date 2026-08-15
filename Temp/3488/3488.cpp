// Link: https://leetcode.com/problems/closest-equal-element-queries/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) groups[nums[i]].push_back(i);

        vector<int> ans(n, -1);
        for (auto& [val, idxs] : groups) {
            int m = idxs.size();
            if (m < 2) continue;
            for (int k = 0; k < m; k++) {
                int cur = idxs[k];
                int nxt = idxs[(k + 1) % m];
                int d = nxt - cur;
                if (d < 0) d += n;
                int prv = idxs[(k - 1 + m) % m];
                int d2 = cur - prv;
                if (d2 < 0) d2 += n;
                ans[cur] = min(d, d2);
            }
        }

        vector<int> result;
        for (int q : queries) result.push_back(ans[q]);
        return result;
    }
};
