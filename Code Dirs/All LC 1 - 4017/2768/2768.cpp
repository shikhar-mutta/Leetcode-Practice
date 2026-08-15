// Link: https://leetcode.com/problems/number-of-black-blocks/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        unordered_map<long long, int> blockCount;
        for (auto &c : coordinates) {
            int r = c[0], col = c[1];
            for (int dr = -1; dr <= 0; dr++) {
                for (int dc = -1; dc <= 0; dc++) {
                    int br = r + dr, bc = col + dc;
                    if (br < 0 || bc < 0 || br + 1 >= m || bc + 1 >= n) continue;
                    long long key = (long long)br * n + bc;
                    blockCount[key]++;
                }
            }
        }

        vector<long long> ans(5, 0);
        long long totalBlocks = (long long)(m - 1) * (n - 1);
        long long accounted = 0;
        for (auto &[key, cnt] : blockCount) {
            ans[cnt]++;
            accounted++;
        }
        ans[0] = totalBlocks - accounted;
        return ans;
    }
};
