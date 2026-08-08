// Link: https://leetcode.com/problems/two-city-scheduling/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });
        int n = costs.size() / 2;
        int total = 0;
        for (int i = 0; i < (int)costs.size(); i++) {
            total += i < n ? costs[i][0] : costs[i][1];
        }
        return total;
    }
};
