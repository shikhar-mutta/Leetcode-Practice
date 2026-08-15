// Link: https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int q = queries.size();
        vector<int> ans(q, -1);
        vector<vector<pair<int,int>>> pending(n);
        for (int i = 0; i < q; i++) {
            int a = queries[i][0], b = queries[i][1];
            if (a > b) swap(a, b);
            if (a == b || heights[a] < heights[b]) ans[i] = b;
            else pending[b].push_back({max(heights[a], heights[b]), i});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> heap;
        for (int i = 0; i < n; i++) {
            while (!heap.empty() && heap.top().first < heights[i]) {
                ans[heap.top().second] = i;
                heap.pop();
            }
            for (auto& p : pending[i]) heap.push(p);
        }
        return ans;
    }
};
