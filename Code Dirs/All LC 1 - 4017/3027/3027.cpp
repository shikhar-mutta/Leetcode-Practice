// Link: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        int n = points.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                if (points[j][1] <= points[i][1]) {
                    if (points[j][1] > maxY) {
                        cnt++;
                        maxY = points[j][1];
                    }
                }
            }
        }
        return cnt;
    }
};
