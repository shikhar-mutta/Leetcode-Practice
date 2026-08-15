// Link: https://leetcode.com/problems/average-waiting-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long curTime = 0;
        long long totalWait = 0;
        for (auto& c : customers) {
            curTime = max(curTime, (long long)c[0]) + c[1];
            totalWait += curTime - c[0];
        }
        return (double)totalWait / customers.size();
    }
};
