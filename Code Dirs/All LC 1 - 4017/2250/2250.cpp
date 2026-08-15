// Link: https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> buckets(101);
        for (auto& r : rectangles) buckets[r[1]].push_back(r[0]);
        for (auto& b : buckets) sort(b.begin(), b.end());

        vector<int> res(points.size());
        for (int i = 0; i < (int)points.size(); i++) {
            int x = points[i][0], y = points[i][1];
            int count = 0;
            for (int h = y; h <= 100; h++) {
                auto& b = buckets[h];
                count += b.end() - lower_bound(b.begin(), b.end(), x);
            }
            res[i] = count;
        }
        return res;
    }
};
