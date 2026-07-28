// Link: https://leetcode.com/problems/minimum-interval-to-include-each-query/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O((n + q) log n)  SC: O(n + q)
// Approach: sort intervals by start. Process queries in increasing order,
// pushing intervals whose start <= query into a min-heap keyed by size, then
// pop expired intervals (end < query) off the top. Heap top gives the answer.
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        int q = queries.size();
        vector<int> idx(q);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return queries[a] < queries[b]; });

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // (size, end)
        vector<int> ans(q, -1);
        int i = 0, n = intervals.size();
        for (int qi : idx) {
            int query = queries[qi];
            while (i < n && intervals[i][0] <= query) {
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            while (!pq.empty() && pq.top().second < query) pq.pop();
            if (!pq.empty()) ans[qi] = pq.top().first;
        }
        return ans;
    }
};
