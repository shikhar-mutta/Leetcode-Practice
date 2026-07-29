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
                int prev = idxs[(k - 1 + m) % m];
                int next = idxs[(k + 1) % m];
                int cur = idxs[k];
                int distNext = (next - cur + n) % n;
                int distPrev = (cur - prev + n) % n;
                ans[cur] = min(distNext, distPrev);
            }
        }

        int q = queries.size();
        vector<int> res(q);
        for (int i = 0; i < q; i++) res[i] = ans[queries[i]];
        return res;
    }
};
