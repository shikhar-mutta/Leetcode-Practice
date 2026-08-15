// Link: https://leetcode.com/problems/buildings-with-an-ocean-view/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        int maxH = -1;
        for (int i = heights.size() - 1; i >= 0; i--) {
            if (heights[i] > maxH) {
                res.push_back(i);
                maxH = heights[i];
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
