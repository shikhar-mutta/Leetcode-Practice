// Link: https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        unordered_set<int> sums = {0};
        for (auto& row : mat) {
            unordered_set<int> nsums;
            for (int s : sums) {
                for (int v : row) {
                    nsums.insert(s + v);
                }
            }
            sums = nsums;
        }
        int best = INT_MAX;
        for (int s : sums) best = min(best, abs(s - target));
        return best;
    }
};
