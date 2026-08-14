// Link: https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int best = 0;
        for (int bit = 0; bit < 24; bit++) {
            int count = 0;
            for (int x : candidates) if ((x >> bit) & 1) count++;
            best = max(best, count);
        }
        return best;
    }
};
