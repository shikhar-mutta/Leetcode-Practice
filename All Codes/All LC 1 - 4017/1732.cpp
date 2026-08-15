// Link: https://leetcode.com/problems/find-the-highest-altitude/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur = 0, best = 0;
        for (int g : gain) {
            cur += g;
            best = max(best, cur);
        }
        return best;
    }
};
