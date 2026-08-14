// Link: https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int best = special[0] - bottom;
        for (int i = 1; i < (int)special.size(); i++) {
            best = max(best, special[i] - special[i-1] - 1);
        }
        best = max(best, top - special.back());
        return best;
    }
};
