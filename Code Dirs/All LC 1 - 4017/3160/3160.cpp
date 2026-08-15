// Link: https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> ballColor;
        unordered_map<int,int> colorCount;
        vector<int> res;
        for (auto& q : queries) {
            int ball = q[0], color = q[1];
            if (ballColor.count(ball)) {
                int oldColor = ballColor[ball];
                if (oldColor != color) {
                    colorCount[oldColor]--;
                    if (colorCount[oldColor] == 0) colorCount.erase(oldColor);
                    colorCount[color]++;
                }
            } else {
                colorCount[color]++;
            }
            ballColor[ball] = color;
            res.push_back(colorCount.size());
        }
        return res;
    }
};
