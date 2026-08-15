// Link: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xs;
        for (auto& p : points) xs.push_back(p[0]);
        sort(xs.begin(), xs.end());
        int best = 0;
        for (int i = 1; i < (int)xs.size(); i++) best = max(best, xs[i] - xs[i-1]);
        return best;
    }
};
