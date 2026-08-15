// Link: https://leetcode.com/problems/maximum-spending-after-buying-items/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        int m = values.size(), n = values[0].size();
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
        for (int i = 0; i < m; i++) pq.push({values[i][n-1], i, n-1});
        long long ans = 0;
        long long day = 1;
        while (!pq.empty()) {
            auto [val, row, col] = pq.top(); pq.pop();
            ans += (long long)val * day;
            day++;
            if (col - 1 >= 0) pq.push({values[row][col-1], row, col-1});
        }
        return ans;
    }
};
