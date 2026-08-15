// Link: https://leetcode.com/problems/construct-the-rectangle/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sqrt(area))  SC: O(1)
// Approach: start w at sqrt(area) and decrease until area % w == 0
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = (int)sqrt((double)area);
        while (area % w != 0) w--;
        return {area / w, w};
    }
};
