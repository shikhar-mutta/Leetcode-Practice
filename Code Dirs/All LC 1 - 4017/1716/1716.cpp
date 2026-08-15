// Link: https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int total = 0;
        int week = 0;
        int day = 0;
        for (int i = 0; i < n; i++) {
            total += 1 + week + day;
            day++;
            if (day == 7) { day = 0; week++; }
        }
        return total;
    }
};
