// Link: https://leetcode.com/problems/car-fleet-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ans(n, -1.0);
        vector<int> stk; // indices, monotonic
        for (int i = n - 1; i >= 0; i--) {
            long long p = cars[i][0], s = cars[i][1];
            while (!stk.empty()) {
                int j = stk.back();
                long long p2 = cars[j][0], s2 = cars[j][1];
                if (s <= s2) { stk.pop_back(); continue; }
                double t = (double)(p2 - p) / (s - s2);
                if (ans[j] > 0 && t > ans[j]) { stk.pop_back(); continue; }
                break;
            }
            if (stk.empty()) ans[i] = -1.0;
            else {
                int j = stk.back();
                long long p2 = cars[j][0], s2 = cars[j][1];
                ans[i] = (double)(p2 - p) / (s - s2);
            }
            stk.push_back(i);
        }
        return ans;
    }
};
