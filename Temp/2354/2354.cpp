// Link: https://leetcode.com/problems/number-of-excellent-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> uniq(nums.begin(), nums.end());
        vector<int> pc;
        for (int x : uniq) pc.push_back(__builtin_popcount(x));
        sort(pc.begin(), pc.end());
        int m = pc.size();
        vector<long long> suffixCount(m + 1, 0);
        for (int i = m - 1; i >= 0; i--) suffixCount[i] = suffixCount[i + 1] + 1;

        long long total = 0;
        for (int i = 0; i < m; i++) {
            int need = k - pc[i];
            int idx = lower_bound(pc.begin(), pc.end(), need) - pc.begin();
            total += suffixCount[idx];
        }
        return total;
    }
};
