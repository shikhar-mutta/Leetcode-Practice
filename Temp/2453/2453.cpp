// Link: https://leetcode.com/problems/destroy-sequential-targets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> count;
        for (int x : nums) count[x % space]++;

        int bestCount = 0;
        for (auto &[rem, c] : count) bestCount = max(bestCount, c);

        int ans = INT_MAX;
        for (int x : nums) {
            if (count[x % space] == bestCount) ans = min(ans, x);
        }
        return ans;
    }
};
