// Link: https://leetcode.com/problems/flip-string-to-monotone-increasing/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = 0, flips = 0;
        for (char c : s) {
            if (c == '1') ones++;
            else flips = min(flips + 1, ones);
        }
        return flips;
    }
};
