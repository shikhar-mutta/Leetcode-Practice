// Link: https://leetcode.com/problems/walking-robot-simulation-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Robot {
    int w, h;
    long long perimeter;
    long long moved = 0;
public:
    Robot(int width, int height) {
        w = width; h = height;
        perimeter = 2LL * (w + h) - 4;
    }

    void step(int num) {
        moved += num;
    }

    vector<int> getPos() {
        long long eff = moved % perimeter;
        int w1 = w - 1, h1 = h - 1;
        if (eff == 0) return {0, 0};
        if (eff < w1) return {(int)eff, 0};
        if (eff < w1 + h1) return {w1, (int)(eff - w1)};
        if (eff < w1 + h1 + w1) return {(int)(w1 - (eff - w1 - h1)), h1};
        return {0, (int)(h1 - (eff - w1 - h1 - w1))};
    }

    string getDir() {
        long long eff = moved % perimeter;
        int w1 = w - 1, h1 = h - 1;
        if (eff == 0) return "East";
        if (eff < w1) return "East";
        if (eff < w1 + h1) return "North";
        if (eff < w1 + h1 + w1) return "West";
        return "South";
    }
};
