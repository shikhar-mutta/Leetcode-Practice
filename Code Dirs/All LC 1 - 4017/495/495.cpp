// Link: https://leetcode.com/problems/teemo-attacking/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: for each attack, add min(duration, gap to next attack)
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;
        for (int i = 0; i < (int)timeSeries.size(); i++) {
            if (i + 1 < (int)timeSeries.size()) {
                total += min(duration, timeSeries[i+1] - timeSeries[i]);
            } else {
                total += duration;
            }
        }
        return total;
    }
};
