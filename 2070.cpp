// Link: https://leetcode.com/problems/most-beautiful-item-for-each-query/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn + mlogn) where n is the number of items and m is the number of queries.
    // SC: O(n) where n is the number of items.
    // Approach:
    // 1. Create a vector of pairs to store the price and beauty of each item.
    // 2. Sort the items based on their price.
    // 3. Iterate through the items and for each item, update the maximum beauty of items that have a price less than or equal to the current item's price.
    // 4. For each query, use binary search to find the maximum beauty of items that have a price less than or equal to the query price.
    // 5. Return the maximum beauty for each query.
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        // [1,2],[2,4],[3,2],[3,5],[5,6]
        // [1,2],[2,4],[3,4],[3,5],[5,6]

        vector<pair<int, int>> v;
        int n = items.size();

        for (auto &item : items)
            v.emplace_back(item[0], item[1]);

        sort(v.begin(), v.end());

        int max_beauty = 0;
        for (auto &[p, b] : v)
        {
            max_beauty = max(max_beauty, b);
            b = max_beauty;
        }

        // for (auto &[p, b] : v) {
        //     cout << "(" << p << ", " << b << ")" << endl;
        // }

        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++)
        {
            int x = queries[i];
            auto it = upper_bound(v.begin(), v.end(), make_pair(x, INT_MAX));

            if (it != v.begin())
                it = prev(it);
            else if (it->first > x)
                continue;

            ans[i] = it->second;
        }

        return ans;
    }
};