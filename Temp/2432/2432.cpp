// Link: https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int bestId = logs[0][0], bestTime = logs[0][1];
        int prev = 0;
        for (auto &log : logs) {
            int id = log[0], t = log[1];
            int dur = t - prev;
            if (dur > bestTime || (dur == bestTime && id < bestId)) {
                bestTime = dur;
                bestId = id;
            }
            prev = t;
        }
        return bestId;
    }
};
