// Link: https://leetcode.com/problems/maximum-balanced-shipments/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int count = 0;
        int runningMax = -1;
        bool inSegment = false;
        for (int i = 0; i < n; i++) {
            if (!inSegment) {
                runningMax = weight[i];
                inSegment = true;
            } else {
                runningMax = max(runningMax, weight[i]);
            }
            if (weight[i] < runningMax) {
                count++;
                inSegment = false;
            }
        }
        return count;
    }
};
