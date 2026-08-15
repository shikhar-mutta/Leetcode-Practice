// Link: https://leetcode.com/problems/minimum-interval-to-include-each-query/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        int m = queries.size();
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // {size, right}
        vector<int> res(m, -1);
        int i = 0;
        for (int qi : idx) {
            int q = queries[qi];
            while (i < (int)intervals.size() && intervals[i][0] <= q) {
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            while (!pq.empty() && pq.top().second < q) pq.pop();
            if (!pq.empty()) res[qi] = pq.top().first;
        }
        return res;
    }
};
