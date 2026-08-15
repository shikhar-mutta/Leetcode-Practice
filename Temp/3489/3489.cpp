// Link: https://leetcode.com/problems/zero-array-transformation-iv/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        const int MAXV = 1001;
        vector<bitset<MAXV>> reach(n);
        for (int i = 0; i < n; i++) reach[i][0] = 1;

        vector<bool> done(n, false);
        int doneCount = 0;
        for (int i = 0; i < n; i++) if (nums[i] == 0) { done[i] = true; doneCount++; }
        if (doneCount == n) return 0;

        for (int k = 0; k < (int)queries.size(); k++) {
            int l = queries[k][0], r = queries[k][1], val = queries[k][2];
            for (int j = l; j <= r && j < n; j++) {
                if (done[j]) continue;
                reach[j] |= reach[j] << val;
                if (nums[j] < MAXV && reach[j][nums[j]]) { done[j] = true; doneCount++; }
            }
            if (doneCount == n) return k + 1;
        }
        return -1;
    }
};
