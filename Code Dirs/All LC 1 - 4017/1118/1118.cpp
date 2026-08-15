// Link: https://leetcode.com/problems/number-of-days-in-a-month/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfDays(int year, int month) {
        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
        bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (month == 2 && leap) return 29;
        return days[month - 1];
    }
};
