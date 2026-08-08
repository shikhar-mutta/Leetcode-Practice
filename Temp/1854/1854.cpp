// Link: https://leetcode.com/problems/maximum-population-year/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int delta[2051] = {0};
        for (auto& l : logs) {
            delta[l[0]]++;
            delta[l[1]]--;
        }
        int best = 0, bestYear = 1950, cur = 0;
        for (int y = 1950; y <= 2050; y++) {
            cur += delta[y];
            if (cur > best) { best = cur; bestYear = y; }
        }
        return bestYear;
    }
};
