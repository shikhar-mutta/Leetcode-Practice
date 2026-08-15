// Link: https://leetcode.com/problems/convert-date-to-binary/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        auto toBin = [](int x) {
            string s;
            while (x > 0) { s += ('0' + (x & 1)); x >>= 1; }
            reverse(s.begin(), s.end());
            return s;
        };
        return toBin(year) + "-" + toBin(month) + "-" + toBin(day);
    }
};
