// Link: https://leetcode.com/problems/points-that-intersect-with-cars/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        set<int> pts;
        for (auto& c : nums)
            for (int x = c[0]; x <= c[1]; x++) pts.insert(x);
        return pts.size();
    }
};
