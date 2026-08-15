// Link: https://leetcode.com/problems/binary-watch/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)  SC: O(1)
// Approach: enumerate all hour/minute combos, keep those whose combined
// popcount matches turnedOn
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    string mm = m < 10 ? "0" + to_string(m) : to_string(m);
                    res.push_back(to_string(h) + ":" + mm);
                }
            }
        }
        return res;
    }
};
