// Link: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReach(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            int lo = max(0, i - ranges[i]);
            int hi = min(n, i + ranges[i]);
            maxReach[lo] = max(maxReach[lo], hi);
        }

        int taps = 0, curEnd = 0, farthest = 0;
        for (int i = 0; i < n; i++) {
            farthest = max(farthest, maxReach[i]);
            if (i == curEnd) {
                if (farthest <= curEnd) return -1;
                taps++;
                curEnd = farthest;
            }
        }
        return taps;
    }
};
