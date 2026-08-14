// Link: https://leetcode.com/problems/count-days-spent-together/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dayOfYear(const string &date) {
        static int cum[13] = {0,0,31,59,90,120,151,181,212,243,273,304,334};
        int month = stoi(date.substr(0,2));
        int day = stoi(date.substr(3,2));
        return cum[month] + day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int a1 = dayOfYear(arriveAlice), a2 = dayOfYear(leaveAlice);
        int b1 = dayOfYear(arriveBob), b2 = dayOfYear(leaveBob);
        int lo = max(a1, b1), hi = min(a2, b2);
        return max(0, hi - lo + 1);
    }
};
