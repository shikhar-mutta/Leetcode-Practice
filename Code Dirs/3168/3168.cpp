// Link: https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumChairs(string s) {
        // E = enter (occupy), L = leave (free); answer = peak simultaneous occupancy
        int cur = 0, peak = 0;
        for (char c : s) {
            cur += (c == 'E') ? 1 : -1;
            peak = max(peak, cur);
        }
        return peak;
    }
};
