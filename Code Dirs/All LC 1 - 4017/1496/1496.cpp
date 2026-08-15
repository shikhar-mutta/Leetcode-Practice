// Link: https://leetcode.com/problems/path-crossing/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> visited;
        int x = 0, y = 0;
        visited.insert({0, 0});
        for (char c : path) {
            if (c == 'N') y++;
            else if (c == 'S') y--;
            else if (c == 'E') x++;
            else if (c == 'W') x--;
            if (!visited.insert({x, y}).second) return true;
        }
        return false;
    }
};
