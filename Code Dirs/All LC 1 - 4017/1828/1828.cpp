// Link: https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for (auto& q : queries) {
            int cnt = 0;
            for (auto& p : points) {
                int dx = p[0] - q[0], dy = p[1] - q[1];
                if (dx * dx + dy * dy <= q[2] * q[2]) cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }
};
