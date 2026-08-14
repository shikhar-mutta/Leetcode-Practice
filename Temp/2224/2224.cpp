// Link: https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int convertTime(string current, string correct) {
        int c1 = stoi(current.substr(0,2)) * 60 + stoi(current.substr(3,2));
        int c2 = stoi(correct.substr(0,2)) * 60 + stoi(correct.substr(3,2));
        int diff = c2 - c1;
        int ops = 0;
        int steps[] = {60, 15, 5, 1};
        for (int s : steps) {
            ops += diff / s;
            diff %= s;
        }
        return ops;
    }
};
