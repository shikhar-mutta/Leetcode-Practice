// Link: https://leetcode.com/problems/best-sightseeing-pair/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int best = INT_MIN;
        int bestLeft = values[0];
        for (int j = 1; j < (int)values.size(); j++) {
            best = max(best, bestLeft + values[j] - j);
            bestLeft = max(bestLeft, values[j] + j);
        }
        return best;
    }
};
