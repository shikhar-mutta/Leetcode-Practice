// Link: https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int toMinutes(const string& t) {
        int h = stoi(t.substr(0, 2));
        int m = stoi(t.substr(3, 2));
        return h * 60 + m;
    }

    int numberOfRounds(string loginTime, string logoutTime) {
        int start = toMinutes(loginTime);
        int end = toMinutes(logoutTime);
        if (end < start) end += 24 * 60;

        int roundStart = (start + 14) / 15 * 15;
        int roundEnd = end / 15 * 15;
        if (roundEnd <= roundStart) return 0;
        return (roundEnd - roundStart) / 15;
    }
};
