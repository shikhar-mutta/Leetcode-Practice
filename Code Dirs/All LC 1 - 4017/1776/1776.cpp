// Link: https://leetcode.com/problems/car-fleet-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> res(n, -1.0);
        vector<int> stack;
        for (int i = n - 1; i >= 0; i--) {
            double pos = cars[i][0], speed = cars[i][1];
            while (!stack.empty()) {
                int j = stack.back();
                double pj = cars[j][0], sj = cars[j][1];
                if (speed <= sj) { stack.pop_back(); continue; }
                double t = (pj - pos) / (speed - sj);
                if (res[j] > 0 && t > res[j]) { stack.pop_back(); continue; }
                break;
            }
            if (stack.empty()) {
                res[i] = -1.0;
            } else {
                int j = stack.back();
                double pj = cars[j][0], sj = cars[j][1];
                res[i] = (pj - pos) / (speed - sj);
            }
            stack.push_back(i);
        }
        return res;
    }
};
