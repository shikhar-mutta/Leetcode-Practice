// Link: https://leetcode.com/problems/maximum-profit-of-operating-a-centennial-wheel/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int waiting = 0;
        long long profit = 0, bestProfit = 0;
        int bestRotation = -1, rotation = 0;

        for (int i = 0; i < (int)customers.size() || waiting > 0; i++) {
            if (i < (int)customers.size()) waiting += customers[i];
            int board = min(waiting, 4);
            waiting -= board;
            rotation++;
            profit += (long long)board * boardingCost - runningCost;
            if (profit > bestProfit) {
                bestProfit = profit;
                bestRotation = rotation;
            }
        }
        return bestRotation;
    }
};
