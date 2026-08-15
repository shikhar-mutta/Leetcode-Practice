// Link: https://leetcode.com/problems/number-of-ships-in-a-rectangle/description/

#include <bits/stdc++.h>
using namespace std;

class Sea {
public:
    vector<vector<int>> ships;

    bool hasShips(vector<int> topRight, vector<int> bottomLeft) {
        for (auto& s : ships) {
            if (s[0] >= bottomLeft[0] && s[0] <= topRight[0] &&
                s[1] >= bottomLeft[1] && s[1] <= topRight[1]) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        if (bottomLeft[0] > topRight[0] || bottomLeft[1] > topRight[1]) return 0;
        if (!sea.hasShips(topRight, bottomLeft)) return 0;
        if (topRight[0] == bottomLeft[0] && topRight[1] == bottomLeft[1]) return 1;

        int midX = (topRight[0] + bottomLeft[0]) / 2;
        int midY = (topRight[1] + bottomLeft[1]) / 2;

        int count = 0;
        count += countShips(sea, {midX, midY}, bottomLeft);
        count += countShips(sea, topRight, {midX + 1, midY + 1});
        count += countShips(sea, {midX, topRight[1]}, {bottomLeft[0], midY + 1});
        count += countShips(sea, {topRight[0], midY}, {midX + 1, bottomLeft[1]});
        return count;
    }
};
