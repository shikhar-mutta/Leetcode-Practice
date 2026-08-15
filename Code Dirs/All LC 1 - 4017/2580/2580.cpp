// Link: https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        const long long MOD = 1e9 + 7;
        sort(ranges.begin(), ranges.end());
        int groups = 0;
        int i = 0, n = ranges.size();
        while (i < n) {
            int end = ranges[i][1];
            int j = i + 1;
            while (j < n && ranges[j][0] <= end) {
                end = max(end, ranges[j][1]);
                j++;
            }
            groups++;
            i = j;
        }

        long long ans = 1;
        for (int k = 0; k < groups; k++) ans = ans * 2 % MOD;
        return (int)ans;
    }
};
