// Link: https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumTime(string time) {
        string t = time;
        if (t[0] == '?') {
            t[0] = (t[1] == '?' || t[1] <= '3') ? '2' : '1';
        }
        if (t[1] == '?') {
            t[1] = (t[0] == '2') ? '3' : '9';
        }
        if (t[3] == '?') t[3] = '5';
        if (t[4] == '?') t[4] = '9';
        return t;
    }
};
