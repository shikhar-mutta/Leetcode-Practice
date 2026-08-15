// Link: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int ax = points[i][0], ay = points[i][1];
                int bx = points[j][0], by = points[j][1];
                if (ax > bx || ay < by) continue;
                bool valid = true;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    int px = points[k][0], py = points[k][1];
                    if (px >= ax && px <= bx && py <= ay && py >= by) { valid = false; break; }
                }
                if (valid) cnt++;
            }
        }
        return cnt;
    }
};
