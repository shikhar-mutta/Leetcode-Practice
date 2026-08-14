// Link: https://leetcode.com/problems/snake-in-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int r = 0, c = 0;
        for (auto& cmd : commands) {
            if (cmd == "UP") r--;
            else if (cmd == "DOWN") r++;
            else if (cmd == "LEFT") c--;
            else if (cmd == "RIGHT") c++;
        }
        return r * n + c;
    }
};
