// Link: https://leetcode.com/problems/max-value-of-equation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int,int>> dq; // (yi - xi, xi)
        int best = INT_MIN;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            while (!dq.empty() && x - dq.front().second > k) dq.pop_front();
            if (!dq.empty()) best = max(best, y + x + dq.front().first);
            while (!dq.empty() && dq.back().first <= y - x) dq.pop_back();
            dq.push_back({y - x, x});
        }
        return best;
    }
};
