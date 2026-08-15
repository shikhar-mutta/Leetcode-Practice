// Link: https://leetcode.com/problems/button-with-longest-push-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int bestIdx = events[0][0];
        int bestTime = events[0][1];
        int prevTime = events[0][1];
        for (int i = 1; i < (int)events.size(); i++) {
            int idx = events[i][0], t = events[i][1];
            int duration = t - prevTime;
            if (duration > bestTime || (duration == bestTime && idx < bestIdx)) {
                bestTime = duration;
                bestIdx = idx;
            }
            prevTime = t;
        }
        return bestIdx;
    }
};
