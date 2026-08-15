// Link: https://leetcode.com/problems/number-of-days-between-two-dates/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isLeap(int y) {
        return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
    }

    int daysFromEpoch(int y, int m, int d) {
        int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int days = 0;
        for (int i = 1971; i < y; i++) days += isLeap(i) ? 366 : 365;
        for (int i = 0; i < m - 1; i++) {
            days += daysInMonth[i];
            if (i == 1 && isLeap(y)) days++;
        }
        days += d;
        return days;
    }

    int daysBetweenDates(string date1, string date2) {
        int y1 = stoi(date1.substr(0,4)), m1 = stoi(date1.substr(5,2)), d1 = stoi(date1.substr(8,2));
        int y2 = stoi(date2.substr(0,4)), m2 = stoi(date2.substr(5,2)), d2 = stoi(date2.substr(8,2));
        return abs(daysFromEpoch(y1,m1,d1) - daysFromEpoch(y2,m2,d2));
    }
};
