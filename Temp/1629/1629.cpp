// Link: https://leetcode.com/problems/slowest-key/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int bestDur = releaseTimes[0];
        char bestKey = keysPressed[0];
        for (int i = 1; i < (int)releaseTimes.size(); i++) {
            int dur = releaseTimes[i] - releaseTimes[i - 1];
            if (dur > bestDur || (dur == bestDur && keysPressed[i] > bestKey)) {
                bestDur = dur;
                bestKey = keysPressed[i];
            }
        }
        return bestKey;
    }
};
