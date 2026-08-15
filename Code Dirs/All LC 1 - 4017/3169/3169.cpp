// Link: https://leetcode.com/problems/count-days-without-meetings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        long long covered = 0;
        int curStart = -1, curEnd = -1;
        for (auto& m : meetings) {
            if (m[0] > curEnd) {
                if (curEnd != -1) covered += curEnd - curStart + 1;
                curStart = m[0];
                curEnd = m[1];
            } else {
                curEnd = max(curEnd, m[1]);
            }
        }
        if (curEnd != -1) covered += curEnd - curStart + 1;
        return (int)(days - covered);
    }
};
