// Link: https://leetcode.com/problems/most-beautiful-item-for-each-query/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), [](auto& a, auto& b) { return a[0] < b[0]; });
        int n = items.size();
        vector<int> prices(n), prefMax(n);
        int best = 0;
        for (int i = 0; i < n; i++) {
            prices[i] = items[i][0];
            best = max(best, items[i][1]);
            prefMax[i] = best;
        }
        vector<int> res;
        for (int q : queries) {
            int idx = upper_bound(prices.begin(), prices.end(), q) - prices.begin();
            res.push_back(idx == 0 ? 0 : prefMax[idx - 1]);
        }
        return res;
    }
};
