// Link: https://leetcode.com/problems/day-of-the-week/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int q = day, m = month, y = year;
        if (m < 3) { m += 12; y--; }
        int K = y % 100, J = y / 100;
        int h = (q + (13*(m+1))/5 + K + K/4 + J/4 + 5*J) % 7;
        vector<string> days = {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
        return days[h];
    }
};
