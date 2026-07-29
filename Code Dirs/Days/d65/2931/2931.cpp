// Link: https://leetcode.com/problems/maximum-spending-after-buying-items/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(M*N log(M*N)), SC: O(M*N)
// Approach: within each shop the items must be bought cheapest-first (that constraint is already
// how each row is sorted). Flattening every item and buying strictly in global ascending price
// order simultaneously satisfies every shop's internal order, and to minimize total cost per
// dollar-of-day-weight (cheap items should get small day multipliers), sorting all items
// ascending and assigning day = rank is optimal. Cost = sum(value * day).
class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        vector<int> all;
        for (auto& row : values) for (int v : row) all.push_back(v);
        sort(all.begin(), all.end());

        long long ans = 0;
        for (int i = 0; i < (int)all.size(); i++) ans += (long long)all[i] * (i + 1);
        return ans;
    }
};
