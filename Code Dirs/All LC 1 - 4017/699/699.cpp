// Link: https://leetcode.com/problems/falling-squares/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n)
// Approach: for each square, scan all previously placed squares for horizontal overlap, take max height among overlaps as the base, add current side length, record height; track running max as running answer.
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> left(n), right(n), height(n);
        for (int i = 0; i < n; i++) {
            left[i] = positions[i][0];
            right[i] = positions[i][0] + positions[i][1];
        }
        vector<int> res;
        int runningMax = 0;
        for (int i = 0; i < n; i++) {
            int base = 0;
            for (int j = 0; j < i; j++) {
                if (left[i] < right[j] && left[j] < right[i]) base = max(base, height[j]);
            }
            height[i] = base + positions[i][1];
            runningMax = max(runningMax, height[i]);
            res.push_back(runningMax);
        }
        return res;
    }
};
