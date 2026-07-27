// Link: https://leetcode.com/problems/number-of-elapsed-seconds-between-two-times/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) SC: O(1)
// Approach: parse HH:MM:SS into total seconds for each time and
// subtract.
class Solution {
    int toSeconds(const string& t) {
        int h = stoi(t.substr(0, 2));
        int m = stoi(t.substr(3, 2));
        int s = stoi(t.substr(6, 2));
        return h * 3600 + m * 60 + s;
    }
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        return toSeconds(endTime) - toSeconds(startTime);
    }
};
